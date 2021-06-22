<?
class file_str extends lib_road{
	function file_str_($filename){
		$fp = file($filename);
		for($i = 0;$i<count($fp);$i++){
			$kk[$i] = chop($fp[$i]);
		}
		return $kk;
	}
}
?>