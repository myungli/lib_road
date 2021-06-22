<?php
class admin_paging2 extends lib_road
{
    function admin_paging2_( $page, $row_page, $get_text, $p_text, $n_text, $page_name = "" )
    {
        $get_text = str_replace( "page={$page}&", "", $get_text );
        if ( $row_page[before] )
        {
            $p_echo[pre] = "<a id='page_pre_id' class='page_pre_class' href=\"{$page_name}?page={$row_page['before']}&{$get_text}\" onMouseOver=\"status='이전';return true;\" onMouseOut=\"status=''\">{$p_text}</a>";
        }
        $i = $row_page[first_page] + 1;
        for ( ; $i <= $row_page[last_page]; ++$i )
        {
            if ( $page == $i )
            {
                $p_echo[pno] .= "<a href='#' id='page_pno_id1' class='page_pno_class1' onclick='return false;' style='cursor:default;'>$i</a>";
            }
            else
            {
                $p_echo[pno] .= "<a href=$page_name?page=$i&$get_text id='page_pno_id2' class='page_pno_class2'>$i</a>";
            }
        }
        if ( $row_page[after] )
        {
            $p_echo['next'] = " <a id='page_next_id' class='page_next_class' href=\"{$page_name}?page={$row_page['after']}&{$get_text}\" onMouseOver=\"status='다음';return true;\" onMouseOut=\"status=''\">$n_text</a>";
        }
        return $p_echo;
    }
}
?>