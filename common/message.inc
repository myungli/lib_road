<?
class message extends lib_road{
	function message_($cont,$action,$exit){
//			<span style='font-size: 10px;color: #999999;'>$cont</span>
		echo "
			<script>alert('$cont');$action</script>
		";
		if($exit=="exit"){
			exit;
		}
	}

	function nomessage_($action,$exit){
		echo "
			<script>$action</script>
		";
		if($exit=="exit"){
			exit;
		}
	}

}
?>