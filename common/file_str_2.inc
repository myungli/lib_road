<?
class file_str_2 extends lib_road{
	function file_str_2_($filename){
		if(is_file($filename)){
			$GLOBALS[fp] = file($filename);
			for($i = 0;$i<count($GLOBALS[fp]);$i++){
				$GLOBALS[fp][$i] = chop($GLOBALS[fp][$i]);
			}
		}
	}
}
?>