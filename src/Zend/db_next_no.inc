<?
class db_next_no extends lib_road{
	function db_next_no_($table_name){
		$db_select = $this->lib_hab("db_select");
		$result = $db_select->db_select_("max(no)",$table_name,"","","","");
		$row = mysql_fetch_row($result);
		if(!$row[0]){
			$max = 1;
		}else{
			$max = $row[0] + 1;
		}
		return $max;
	}
}
?>