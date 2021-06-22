<?
class file_open_str extends lib_road{
	function file_open_str_($filename){
		if(is_file($filename)){
			$data='';
			$f=fopen($filename,'rb');
			while(!feof($f)){
				$data.=fread($f,2046);
			}
			fclose($f);
		}
		return $data;
	}
}
?>