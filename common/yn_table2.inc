<?
require_once("/domainhost/nicgocom/lib/lib_road.inc");

class yn_table2 extends lib_road {
    
    function yn_table2_($db_name, $tbl_name) {
        $result = false;
        $rs = mysql_list_tables($db_name);
        if ($rs) {
            while ($name = mysql_fetch_array($rs)) {
                if ($name[0] == $tbl_name) {
                    $result = true;
                    break;
                }
            }
        }

        return $result;
    }
}
?>