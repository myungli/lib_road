<?php
/* Json 변환 */
if (!function_exists('json_encode')) {
    function json_encode($content) {
        require_once './JSON.php';
        $json = new Services_JSON;
        return $json->encode($content);
    }
}
class json_connet extends lib_road{
    function json_connet_($data){
        if ( !is_array($data) ){
            return $this->encodedJson( $data );
        }else{
            return $this->s_encodedJson( $data );
        }
    }
    /* 배열 데이터 변환 */
    function s_encodedJson($data) {
        $encodedJson = json_encode(array("data"=>$data));
        //$encodedJson = urldecode($encodedJson);
        //echo $encodedJson;
        return urldecode($encodedJson);
    }
    /* 데이터 변환 */
    function encodedJson($data) {
        $encodedJson = json_encode($data);
        //$encodedJson = urldecode($encodedJson);
        //echo $encodedJson;
        return urldecode($encodedJson);
    }
}
?>
