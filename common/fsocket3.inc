<?
class fsocket3 extends lib_road{
	var $filePointer;
	function fsocket3_($host,$path, $data,$port,$ssl_yn="N") {
		$boundary = "---------------------".substr(md5(rand(0,32000)),0,10);

		$fsock_data = "";
		$post_data = explode("&",$data);
		$pcount = count($post_data) - 1;
		foreach($post_data as $key=>$value){
			$p_data = explode("=",$value);
			if($pcount!=$key){
				$tip ="";
			}else{
				$tip ="--";
			}
			$fsock_data .= $this->fsocket_post($boundary,$p_data[0],$p_data[1],$tip);
		}

        $requestHeader = "POST $path HTTP/1.0\r\n";
        $requestHeader.= "Host: $host\r\n";
        $requestHeader.= "Content-type: Multipart/form-data, boundary=$boundary\r\n";
//		$requestHeader.= "Content-Type: Application/x-www-form-urlencoded\r\n";
        $requestHeader.= "Content-Length: ". strlen($fsock_data) ."\r\n\r\n";

		if($ssl_yn=="Y"){
			$this->filePointer = fsockopen("ssl://$host", $port, $errno, $errstr,10);
		}else{
			$this->filePointer = fsockopen($host, $port, $errno, $errstr,10);
		}

		if(!$this->filePointer) {
			echo("SendToHost 연결에러: $errstr ($errno)\r\n");
			return false;
		}

		$requestHeader .= $fsock_data;
		fputs($this->filePointer, $requestHeader);
		$retval[0] = fgets($this->filePointer, 4096);
		
		do{
			$requestHeader.= fread($this->filePointer, 1);
		}while (!preg_match('/\\r\\n\\r\\n$/', $requestHeader));
		$responseContent = $this->fsocket_point($requestHeader);

		fclose($this->filePointer);
/*
 		if (!ereg("HTTP/1.0 200 OK", $retval[0])) {
			echo "<script type='text/javascript' language='javascript'>alert('파일 업로드 에러입니다.1.')</script>";
			echo("$responseContent");
			exit;
		}
*/
		return $responseContent;
	}

	function fsocket_post($boundary,$index,$value,$tip=""){
		if($_FILES[$index]['name']){
			$fsock_data .= $this->fsocket_file($boundary,$index,$_FILES[$index]['name'],$tip);
		}else{
			$fsock_data = "--$boundary\r\n";
			$fsock_data .= "Content-Disposition: form-data; name=\"$index\"\r\n";
			$fsock_data .= "\r\n$value\r\n";
			$fsock_data .="--$boundary$tip\r\n";
		}

		return $fsock_data;
	}

	function fsocket_file($boundary,$File_input,$value,$tip){
		if ($_FILES[$File_input]['size']<1) {
			return false;
		}
//		$value = base64_encode($value);
		$content_type = $_FILES[$File_input]['type'];
		$fp = fopen($_FILES[$File_input]['tmp_name'], "r");
		$str_filebody = fread($fp, $_FILES[$File_input]['size']);
		fclose($fp);
//		$str_filebody = chunk_split(base64_encode($str_filebody));
//		$str_filebody = base64_encode(chunk_split($str_filebody));
		$str_filebody = join("",file($_FILES[$File_input]['tmp_name']));
		$fsock_data = "--$boundary\r\n";
		$fsock_data = "Content-Disposition: form-data; name=\"$File_input\"; filename=\"$value\";\r\n";
		$fsock_data.= "Content-Type: $content_type\r\n";
//		$fsock_data.= "Content-Transfer-Encoding: base64\r\n";
		$fsock_data.= "Content-Transfer-Encoding: binary\r\n";
		$fsock_data.= "\r\n$str_filebody\r\n";
		$fsock_data.="--$boundary$tip\r\n";

		return $fsock_data;
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