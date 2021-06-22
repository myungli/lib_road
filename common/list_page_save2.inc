<?
class list_page_save2 extends lib_road{
    function list_page_save2_($not_code=array(),$ctip="1"){
//		session_register("sess_page_list".$ctip);
		$_SESSION["sess_page_list".$ctip]="";
		$page_trans_return = $this->lib_hab("page_trans_return");
		$_SESSION["sess_page_list".$ctip] = $page_trans_return->page_trans_return_($not_code);;
		return $_SESSION["sess_page_list".$ctip];
    }
}
?>