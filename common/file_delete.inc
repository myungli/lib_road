<?
class file_delete extends lib_road{
	function file_delete_($f_url,$f_name){
		if(is_file("$f_url/$f_name")){
			unlink("$f_url/$f_name");
		}
	}
}
?>