<?
class data_one_row_return extends lib_road{
	function data_one_row_return_($field,$table,$where,$orderby,$groupby){//고객 정보
		$db_select = $this->lib_hab("db_select");  //라이브러리 로드
		$result = $db_select->db_select_($field,$table,$where,$orderby,$groupby,"1");
		return mysql_fetch_array($result);
	}
}
?>