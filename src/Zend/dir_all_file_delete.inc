<?
class dir_all_file_delete extends lib_road{
    function dir_all_file_delete_($dir,$tip){//1(경로의 파일만삭제),2(서브파일까지 파일삭제),3(디렉토리까지 삭제)
		if (is_dir($dir) and eregi($_SERVER[DOCUMENT_ROOT],$dir)) {
			$open = opendir($dir);
			while($file=readdir($open)){
//echo("aaa($dir) : $file<br>");
				if($file!="." and $file!=".." and $file!="./"){
					$file = str_replace("./","",$file);
					if(is_file("$dir/$file")){
						unlink("$dir/$file");
					}elseif(is_dir("$dir/$file")){
						if($tip!="1"){
							$this->sub_dir_file_delete_("$dir/$file",$tip);
						}
					}
				}
			}
			closedir($open);
			if($tip=="3"){
				rmdir($dir);
			}
			return true;
        }else{
			return false;
		}
    }

    function sub_dir_file_delete_($dir,$tip){
		if (is_dir($dir) and eregi($_SERVER[DOCUMENT_ROOT],$dir)) {
			$open = opendir($dir);
			while($file=readdir($open)){
//echo("bbb($dir) : $file<br>");
				if($file!="." and $file!=".." and $file!="./"){
					$file = str_replace("./","",$file);
					if(is_file("$dir/$file")){
						unlink("$dir/$file");
					}elseif(is_dir("$dir/$file")){
						$this->sub_dir_file_delete_("$dir/$file",$tip);
					}
				}
			}
			closedir($open);
			if($tip=="3"){
				rmdir($dir);
			}
        }
    }
}
?>