<?
class cont extends lib_road{
	function cont_($cont){
		if(eregi("<table|<div",$cont)){
			$phr = array("\\r\\n","\\n","\\r");
			$hea = array("\r\n","\n","\r");
			$cont = str_replace($phr,$hea,$cont);
		}else{
			$cont = nl2br($cont);
		}
		return $cont;
	}
}
?>