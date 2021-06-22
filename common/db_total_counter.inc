<?
class db_total_counter extends lib_road{
	function db_total_counter_($table,$where){////ÃÑÅõÇ¥¼ö
		$db_select = $this->lib_hab("db_select");
		$result = $db_select->db_select_("count(*) as total",$table,$where,"","","1");
//		echo("bbb : $result<br>");
		$row = mysql_fetch_array($result);
		return $row[total];
	}
}
?>