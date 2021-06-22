<?
class admin_paging_ajax_layer_pop extends lib_road{
	function admin_paging_ajax_layer_pop_($page,$row_page,$get_text,$p_text,$n_text,$table_name=""){//페이징 함수
//echo("page4 : $page : $get_text<br>");
		$get_text = str_replace("page=$page&","",$get_text);
		//echo("page=$page : $get_text<br>");
		if($row_page[before]){// 페이지 번호 출력 제한 갯수 초과시 처음으로 가는 버튼 출력
			$p_echo[pre] = "<div id='page_pre' onclick=\"script_ajax_layer_pop('$PHP_SELF',jQuery('#myform2').serialize()+'&page=$row_page[before]&$get_text','$table_name')\"  onMouseOver=\"status='이전';return true;\" onMouseOut=\"status=''\">$p_text</div>&nbsp;";
		}
		for($i = $row_page[first_page]+1; $i<=$row_page[last_page];$i++){
			if($page==$i){
				$p_echo[pno] .= "<div id='page_on'>&nbsp;$i</div>";
			}else{
				$p_echo[pno] .= "<div class='page_no' href=\"script_ajax_layer_pop('$PHP_SELF',jQuery('#myform2').serialize()+'&page=$i&$get_text','$table_name')\">&nbsp;$i</div>";
			}
		}
		if($row_page[after]){ // 페이지 번호 출력 제한 갯수 초과시 마지막으로 가는 버튼 출력
			$p_echo['next'] = "<div id='page_next' onclick=\"script_ajax_layer_pop('$PHP_SELF',jQuery('#myform2').serialize()+'&page=$row_page[after]&$get_text','$table_name')\" onMouseOver=\"status='다음';return true;\" onMouseOut=\"status=''\">&nbsp;$n_text</a>";
		}
		return $p_echo;
	}
}
?>