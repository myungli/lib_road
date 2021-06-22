<?
class db_total_sum2 extends lib_road{
	function db_total_sum2_($field,$table,$where){////รัล๕วฅผ๖
		$db_select = $this->lib_hab("db_select");
		$result = $db_select->db_select_("sum($field) as tsum,count($field) as tcount",$table,$where,"","","1");
		$row = mysql_fetch_array($result);
		return $row;
	}
}
?>