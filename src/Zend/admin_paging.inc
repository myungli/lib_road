<?
class admin_paging extends lib_road{
	function admin_paging_($page,$row_page,$get_text,$p_text="◀",$n_text="▶"){//페이징 함수
		$get_text = str_replace("page=$page&","",$get_text);
		if($row_page[before]){// 페이지 번호 출력 제한 갯수 초과시 처음으로 가는 버튼 출력
			echo "<a href=\"$PHP_SELP?page=$row_page[before]$get_text\" onMouseOver=\"status='이전';return true;\" onMouseOut=\"status=''\">$p_text</a>&nbsp;";
		}
		for($i = $row_page[first_page]+1; $i<=$row_page[last_page];$i++){
			if($page==$i){
				echo "<font color=red><b>&nbsp;[$i]</b></font>";
			}else{
				echo "<a href=\"$PHP_SELP?page=$i$get_text\">&nbsp;$i</a>";
			}
		}
		if($row_page[after]){ // 페이지 번호 출력 제한 갯수 초과시 마지막으로 가는 버튼 출력
			echo " <a href=\"$PHP_SELP?page=$row_page[after]$get_text\" onMouseOver=\"status='다음';return true;\" onMouseOut=\"status=''\">&nbsp;$n_text</a>";
		}
	}
}
?>