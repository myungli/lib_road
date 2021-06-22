<?
class mlnumber_format extends lib_road{
	function mlnumber_format_($mon,$num_sosu="0"){
		if(stristr($mon,".") and $num_sosu=="0"){
			$num_sosu = "2";
		}
		return number_format($mon,$num_sosu,".",",");
	}
}
?>
