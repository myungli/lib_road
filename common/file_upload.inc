<?
//파일업로드 버전 2.1.1
class file_upload extends lib_road{
	function file_upload_($upfile,$f_dir,$set_name1="",$set_type="",$return_tip="1"){//파일를 복사한다.(파일객체,파일명,저장경로)
		$size_ = ini_get('upload_max_filesize');
		if(ereg("M",$size_)){
			$size_ = str_replace("M","",$size_);
			$size_limit = ($size_ * 1000) * 1024;
		}else{
			$size_limit = $size_ * 1024;
		}

		$message = $this->lib_hab("message");
		if($_FILES[$upfile]['size'] > $size_limit){
			$message->message_("업로드 용량 초과입니다. (제한용량 ".$size_.")","history.back();","exit");
		}

		if(is_null($_FILES[$upfile]['name']) || !file_exists($_FILES[$upfile]['tmp_name'])){
//echo("<br>1testasdfasdf<br>");
			return false;
		}

		$vowels = array(" ", " ", "'", "\"","\/","\\","\;","\`","\%","\#");
		$re_name = explode(".",str_replace($vowels, "", $_FILES[$upfile]['name']),2);//파일네임을 자른다.
		if(!$set_name1){
			$set_name1 = $re_name[0];
		}else{
			$over_tip = "over";
		}

		if(!$set_type){
			$set_type = $re_name[1];
		}

		$img_etc = ".php,.php3,.inc,.asp,.jsp,.js,.htm,.html,.xml,.sh,.pl,.phtml,.php4";
		if(strpos($img_etc,$set_type)){
			$message->message_("허용되지 않은 파일 확장자 입니다.","history.back();","exit");
		}else{
		    if(!is_dir($f_dir)){
		        return false;
		    }
			$f_name = "$f_dir/$set_name1.$set_type";//저장할 파일경로
            
			if(is_file($f_name) and $over_tip!="over"){
				do{//파일이 없을때까지 돌아..
				   $i++;
				   $f_name = "$f_dir/$set_name1$i.$set_type";//저장할 파일경로
				}while(is_file($f_name));
			}

			if(move_uploaded_file($_FILES[$upfile]['tmp_name'],$f_name)){//파일를 이동
				if($return_tip=="2"){
					return $set_type;
				}else{
					return "$set_name1$i.$set_type";
				}
			}else{
//echo("<br>2testasdfasdf<br>");
				return false;
//				$message->message_("파일 저장 실폐 관리자에게 문의 바랍니다.","history.back();","exit");
			}
		}
	}
}
?>