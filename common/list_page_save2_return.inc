<?
class list_page_save2_return extends lib_road{
    function list_page_save2_return_($ctip="1"){
		if($_SESSION["sess_page_list".$ctip]){
			return $_SESSION["sess_page_list".$ctip];
		}
    }
}
?>