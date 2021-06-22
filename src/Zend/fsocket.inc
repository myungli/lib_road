<?
class fsocket extends lib_road{
	var $filePointer;
	function fsocket_($host, $method, $path, $data,$port,$ssl_yn="N"){
		if($ssl_yn=="Y"){
			$this->filePointer = fsockopen("ssl://$host", $port, $errorNumber, $errorString,4);
		}else{
			$this->filePointer = fsockopen($host, $port, $errorNumber, $errorString,4);
		}

		if (!$this->filePointer) {
			echo("error : $errorString($errorNumber)<br>");
			return false;
		}

		$method = strtoupper($method);
		if ($method == "GET"){
			$path.= '?'.$data;
		}

		$requestHeader = $method." ".$path."  HTTP/1.0\r\n";
		$requestHeader.= "Host: ".$host."\r\n";
		$requestHeader.= "User-Agent: Mozilla/5.0 (Windows; U; Windows NT 5.1; en-US; rv:1.8.1) Gecko/20061010 Firefox/2.0\r\n";
		$requestHeader.= "Content-Type: application/x-www-form-urlencoded\r\n";

		if ($method == "POST"){
			$requestHeader.= "Content-Length: ".strlen($data)."\r\n";
		}

		$requestHeader.= "Connection: close\r\n\r\n";

		if ($method == "POST"){
			$requestHeader.= $data;
		}

		fwrite($this->filePointer, $requestHeader);
		do{
			$responseHeader.= fread($this->filePointer, 1);
		}while (!preg_match('/\\r\\n\\r\\n$/', $responseHeader));
		$responseContent = $this->fsocket_point($responseHeader);
		fclose($this->filePointer);
		return $responseContent;
	}

	function fsocket_point($responseHeader){
		if (!strstr($responseHeader, "Transfer-Encoding: chunked")){
			while (!feof($this->filePointer)){
				$responseContent.= fgets($this->filePointer, 128);
			}
		}else{
			while ($chunk_length = hexdec(fgets($this->filePointer))){
				$responseContentChunk = '';
				$read_length = 0;

				while ($read_length < $chunk_length){
					$responseContentChunk .= fread($this->filePointer, $chunk_length - $read_length);
					$read_length = strlen($responseContentChunk);
				}
				$responseContent.= $responseContentChunk;
				fgets($this->filePointer);
			}
		}
		return $responseContent;
	}
}
?>