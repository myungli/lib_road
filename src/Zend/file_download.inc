<?
class file_download extends lib_road{
	function file_download_($upfile,$upfile_path,$err_script="",$down_file="",$auto_str="auto"){
		if($_SERVER[HTTPS]=="on"){
			$page_trans_return=$this->lib_hab("page_trans_return");
			$new_url = "http://$_SERVER[SERVER_NAME]$_SERVER[PHP_SELF]?".$page_trans_return->page_trans_return_();
			$header_print=$this->lib_hab("header_print");
			$header_print->header_print_($new_url,"location");
			exit;
		}
		$message = $this->lib_hab("message");
		if(!$upfile){
			$message->message_("지정된 파일이 없습니다.",$err_script,"exit");
		}
		$f_str = ".php,.php3,.phtml,.inc,.pl,.cgi,.asp,.htm,.html";
		$str = strtolower(substr(strrchr($upfile,"."),1));
		if(!$str){
			$str = "txt";
		}
//		$str = strstr($upfile,".");
		if(stristr($f_str,$str) === TRUE){
			$message->message_("선택하신 파일은 다운로드가 금지된 파일 입니다.",$err_script,"exit");
		}
		$downloadPath = "$upfile_path/$upfile"; // define directory path

		if(!is_file($downloadPath)){
			$message->message_("파일이 없거나 정상적인 파일이 아닙니다.",$err_script,"exit");
		}
		if($down_file){
			if($auto_str=="auto"){
				$upfile = $down_file.".".$str;
			}else{
				$upfile = $down_file;
			}
		}

		$file_ctype_return=$this->lib_hab("file_ctype_return");
		$ctype = $file_ctype_return->file_ctype_return_($str);

		$f_size = filesize($downloadPath);
		header("Pragma: public");
		header("Expires: 0");
		header("Cache-Control: must-revalidate, post-check=0, pre-check=0");
		header("Cache-Control: public");
		header("Content-Description: File Transfer");
		header("Content-Type: $ctype");
		$header="Content-Disposition: attachment; filename=".$upfile.";";
		header($header);
		header("Content-Transfer-Encoding: binary");
		header("Content-Length: ".$f_size);

		$fp=fopen($downloadPath,"r");
		while( $data = fread($fp, $f_size) ){
			echo($data);
		}
		fclose($fp);
	}
}
?>