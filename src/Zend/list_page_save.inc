<?
class list_page_save extends lib_road{
    function list_page_save_($tip="",$ctip="1"){
		if($tip=="list_file"){
			GLOBAL $page;
			session_register("session_page_list".$ctip);
			$page_pgetdata_save = $this->lib_hab("page_pgetdata_save");
			$_SESSION["session_page_list".$ctip] = $page_pgetdata_save->page_pgetdata_save_();;
			return str_replace("page=$page&","",$_SESSION["session_page_list".$ctip]);
		}else{
			if($_SESSION["session_page_list".$ctip]){
				return $_SESSION["session_page_list".$ctip];
			}else{
				session_register("session_page_list".$ctip);
				$_SESSION["session_page_list".$ctip] = $_SERVER[QUERY_STRING];
				return $_SERVER[QUERY_STRING];
			}
		}
    }
}
?>