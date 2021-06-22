<?
class db_total_sum extends lib_road{
	function db_total_sum_($field,$table,$where){////รัล๕วฅผ๖
		$db_select = $this->lib_hab("db_select");
		$result = $db_select->db_select_("sum($field) as tsum",$table,$where,"","","1");
		$row = mysql_fetch_array($result);
		return $row[tsum];
	}
}
?>