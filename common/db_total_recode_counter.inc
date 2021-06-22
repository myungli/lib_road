<?
class db_total_recode_counter extends lib_road{
	function db_total_recode_counter_($table,$where,$groupby=""){////รัล๕วฅผ๖
		$db_select = $this->lib_hab("db_select");
		$result = $db_select->db_select_("*",$table,$where,"",$groupby,"");
		return mysql_affected_rows();
	}
}
?>