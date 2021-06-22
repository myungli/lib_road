<?
class db_update extends lib_road{
	function db_update_($table,$set,$where){
		if(!$table || !$set || !$where){
			echo("field 또는 table 또는 where 인자(3)가 부족합니다.");
			exit;
		}
		if($set){
			$set_ = " set ".$set;
		}
		if($where){
			$where_ = " where ".$where;
		}
		$sql = "UPDATE $table$set_$where_";
		if(!mysql_query($sql)){
			echo mysql_error()." : mysql 에러.<br>";
			return $sql;
		}
	}
}
?>