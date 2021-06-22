<?
class f_write2 extends lib_road{
    function f_write2_($f_name,$input){
		$fp = fopen($f_name,"w");
		if(is_array($input)){
	        fwrite($fp,join("",$input));
		}else{
	        fwrite($fp,$input);
		}
        fclose($fp);
    }
}
?>