<?
class f_write extends lib_road{
    function f_write_($f_name,$input){
        $fp = fopen($f_name,"w");
		ksort($input);
		end($input);
		for($i=0;$i<=key($input);$i++){
			if(!$input[$i]){
				$input[$i] = "\n";
			}
		}
		ksort($input);
        $in = join("",$input);
        fwrite($fp,$in);
        fclose($fp);
    }
}
?>