<?
class db_delete extends lib_road{
	function db_delete_($table,$where){
		if(!$table || !$where){
			echo("table 또는 where 인자(2)가 부족합니다.");
			exit;
		}
		if($where){
			$where_ = " where ".$where;
		}
		$sql = "DELETE FROM $table$where_";
		if(!mysql_query($sql)){
			echo mysql_error()." : mysql 에러.<br>";
			return $sql;
		}
	}
}
?>