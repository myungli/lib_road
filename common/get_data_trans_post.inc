<?php
class get_data_trans_post extends lib_road{
    function get_data_trans_post_($get_params){
        $datas=explode('&',$get_params);
        foreach($datas as $key=>$value){
            list($k,$v)=explode('=',$value);    //form값 =기준으로 키와 값을 분리해주기
            $data[$k] = $v;
            $_POST[$k] = $v;
        }
        return $data;
    }
}
?>