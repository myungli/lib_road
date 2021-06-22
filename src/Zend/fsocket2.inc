<?
class fsocket2 extends lib_road{
	function fsocket2_($host, $method, $path, $data,$port,$ssl_yn="N"){
//		$data = urlencode($data);
		if($ssl_yn=="Y"){//php 4.3.x 버젼 이상 버전에서만 지원
			$filePointer = fsockopen("ssl://$host", $port, $errorNumber, $errorString,4);
		}else{
			$filePointer = fsockopen($host, $port, $errorNumber, $errorString,4);
		}

		if (!$filePointer) {
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

		if(count($_FILES)){
			for($i=0;$i<count($_FILES);$i++){
				if(stristr(("&".$_FILES[$i][name]."="),$data)){
					$requestHeader .= $this->addattachment($_FILES[$i]['name'],$i);
				}
			}
		}
		fwrite($filePointer, $requestHeader);

		$responseHeader = '';
		$responseContent = '';

		do{
			$responseHeader.= fread($filePointer, 1);
		}while (!preg_match('/\\r\\n\\r\\n$/', $responseHeader));


		if (!strstr($responseHeader, "Transfer-Encoding: chunked")){
			while (!feof($filePointer)){
				$responseContent.= fgets($filePointer, 128);
			}
		}else{
			while ($chunk_length = hexdec(fgets($filePointer))){
				$responseContentChunk = '';
				$read_length = 0;

				while ($read_length < $chunk_length){
					$responseContentChunk .= fread($filePointer, $chunk_length - $read_length);
					$read_length = strlen($responseContentChunk);
				}
				$responseContent.= $responseContentChunk;
				fgets($filePointer);
			}
		}
		fclose($filePointer);

		return $responseContent;
	}

	function addattachment($upfile,$parts){
		$vowels = array(" ", " ", "'", "\"","\/","\\","\;","\`","\%","\#");//파일 이름 변경.
		$f_name = str_replace($vowels, "", $_FILES[$upfile]['name']);//파일 네임중 저장되어서 다시 불러 오기않되는 문자들
		$data = file_get_contents($_FILES[$upfile]['tmp_name']);
		$f_type = $_FILES[$upfile]['type'];
		$parts = count($this->parts);
		$content_id = "part$parts." . sprintf("%09d", crc32($f_name)) . strrchr($this->to_address, "@");
		return "--" . $this->boundary . "\n" .
				"Content-Type: $f_type; name=\"$f_name\"\r\n" .
				"Content-Transfer-Encoding: base64\r\n" .
				"Content-ID: <$content_id>\r\n" .
				"Content-Disposition: attachment;" ." filename=\"$f_name\"\r\n" ."\n".
				chunk_split( base64_encode($data), 76, "\n");
	}
}
?>