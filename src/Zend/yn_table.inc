<?
class yn_table extends lib_road{
	function yn_table_($table){
		$result = mysql_query("SHOW TABLES LIKE '$table'");
		$row = @mysql_fetch_row($result);
		if($row[0]){
			return true;
		}else{
			return false;
		}
	}
}
?>