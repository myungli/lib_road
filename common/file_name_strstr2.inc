<?
class file_name_strstr2 extends lib_road{
	function file_name_strstr2_($upfile_array,$f_str=".gif,.jpg,.jpeg"){//파일를 복사한다.(파일객체,파일명,저장경로)
		$message = $this->lib_hab("message");   //라이브러리 로드
		foreach($upfile_array as $key=>$upfile){
			if(file_exists($_FILES[$upfile]['tmp_name'])){
				$str = end(explode(".",$_FILES[$upfile]['name']));
				if(!stristr($f_str,strtolower($str))){
					return $key;
				}
			}
		}
		return "ok";
	}
}
?>