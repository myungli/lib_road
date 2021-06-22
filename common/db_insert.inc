<?
class db_insert extends lib_road{
	function db_insert_($table,$field,$value){
		if(!$table || !$field || !$value){
			echo("field 또는 table 또는 value 인자(3)가 부족합니다.");
			exit;
		}
		$sql = "INSERT INTO $table ($field) values ($value)";
		if(!mysql_query($sql)){
			echo mysql_error()." : mysql 에러.<br>";
			return $sql;
		}
	}
}
?>