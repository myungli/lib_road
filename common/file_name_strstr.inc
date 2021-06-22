
<?
class file_name_strstr extends lib_road{
	function file_name_strstr_($upfile_array,$f_str=".gif,.jpg,.jpeg"){//파일를 복사한다.(파일객체,파일명,저장경로)
		$message = $this->lib_hab("message");   //라이브러리 로드
		foreach($upfile_array as $key=>$upfile){
			if(file_exists($_FILES[$upfile]['tmp_name'])){
				$str = end(explode(".",$_FILES[$upfile]['name']));
				if(!stristr($f_str,strtolower($str))){
					$message->message_("$f_str 속성 파일만 지원 합니다. 다시 시도하세요.","history.back();","exit");
				}
			}
		}
	}
}
?>