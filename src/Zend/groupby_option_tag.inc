<?
class groupby_option_tag extends lib_road{
	function groupby_option_tag_($table,$field,$value,$where,$c_print="",$order_by=""){//사이즈 옵션
		$field_ar = split(",",$field);
		if(count($field_ar)>"2" || count($field_ar)<"1"){
			$message = $this->lib_hab("message");   //라이브러리 로드
			$message->message_("groupby_option_tag (filed 2개이상 에러)","","exit");   //함수 호출
		}

		if(count($field_ar)=="2"){
			$field1 = $field_ar[0];
			$field2 = $field_ar[1];
			$gfield1 = end(explode(".",$field_ar[0]));
			$gfield2 = end(explode(".",$field_ar[1]));
		}else{
			$field1 = $field;
			$field2 = $field;
			$gfield1 = end(explode(".",$field));
			$gfield2 = end(explode(".",$field));
		}

		if($c_print=="count"){
			$c_print = ",FORMAT(count($field1),0) as fcount";
			$prv = "(";
			$nex = ")";
		}else{
			$c_print = "";
		}
		if($order_by){
			$order_by = $order_by.",";
		}
//cho("select ".$field.$c_print." from $table where $where group by $gfield1 order by binary($field2) asc<br>\n");
		$db_select = $this->lib_hab("db_select");  //라이브러리 로드
		$result = $db_select->db_select_($field.$c_print,$table,$where,$order_by."binary($field2) asc",$field1,"");//함수호출

		while($row = mysql_fetch_array($result)){
			$co[$row[$gfield1]] = $row[$gfield2].$prv.$row[fcount].$nex;
		}
		if(count($co)>=1){
			$option = $this->lib_hab("option");
			return $option->option_($value,$co);
		}
	}
}
?>