<?
class db_conn_user extends lib_road{
	function db_conn_user_($user,$pass,$db1){
		if($GLOBALS[conn]){
			mysql_close($GLOBALS[conn]);
		}
		$GLOBALS[conn] = mysql_connect("localhost",$user,$pass) or die("$user MYSQL DB SERVER에 연결할 수 없습니다.");
		if(mysql_select_db("$db1",$GLOBALS[conn]) && $GLOBALS[conn]){
			return true;
		}else{
			return false;
		}
	}
}
?>