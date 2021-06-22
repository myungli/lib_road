<?
class db_select extends lib_road{
	function db_select_($field,$table,$where,$order,$group,$limit){
		if(!$field || !$table){
			echo("field 또는 table 인자(6)가 부족합니다.");
			exit;
		}
		if($where){
			$where_ = " where ".$where;
		}
		if($group){
			$group_ = " group by ".$group;
		}
		if($order){
			$order_ = " order by ".$order;
		}
		if($limit){
			$limit_ = " limit ".$limit;
		}
		$sql = "select $field from $table$where_$group_$order_$limit_";
		$result = mysql_query($sql);
		if(!$result){
			echo mysql_error()." : mysql 에러.<br>";
			return $sql;
		}
		return $result;
	}
}
?>