<?
class admin_paging1 extends lib_road{
	function admin_paging1_($page,$row_page,$get_text,$p_text,$n_text,$page_name=""){//페이징 함수
//echo("page4 : $page : $get_text<br>");
		$get_text = str_replace("page=$page&","",$get_text);
		//echo("page=$page : $get_text<br>");
		if($row_page[before]){// 페이지 번호 출력 제한 갯수 초과시 처음으로 가는 버튼 출력
			$p_echo[pre] = "<a href=\"$page_name?page=$row_page[before]&$get_text\" onMouseOver=\"status='이전';return true;\" onMouseOut=\"status=''\">$p_text</a>";
		}
		for($i = $row_page[first_page]+1; $i<=$row_page[last_page];$i++){
			if($page==$i){
				$p_echo[pno] .= "<font color='#ff6600'><b>&nbsp;[$i]</b></font>";
			}else{
				$p_echo[pno] .= "<a href=\"$page_name?page=$i&$get_text\">&nbsp;$i</a>";
			}
		}
		if($row_page[after]){ // 페이지 번호 출력 제한 갯수 초과시 마지막으로 가는 버튼 출력
			$p_echo['next'] = " <a href=\"$page_name?page=$row_page[after]&$get_text\" onMouseOver=\"status='다음';return true;\" onMouseOut=\"status=''\">&nbsp;$n_text</a>";
		}
		return $p_echo;
	}
}
?>