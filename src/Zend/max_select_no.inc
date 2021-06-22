<?
class max_select_no extends lib_road{
    function max_select_no_($table,$field,$where=""){
        $data_one_row_return = $this->lib_hab("data_one_row_return");  //라이브러리 로드
        $row = $data_one_row_return->data_one_row_return_("max(".$field.") as max_no",$table,$where,"","");//함수호출
        return ($row[max_no] + 1);
    }
}
?>