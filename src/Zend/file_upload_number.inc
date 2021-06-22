<?
class file_upload_number extends lib_road{
    function file_upload_number_($upfile,$path,$permision){
        if(is_null($_FILES[$upfile]['name']) || !file_exists($_FILES[$upfile]['tmp_name'])){
            return "";
        }
  		$message = $this->lib_hab("message");
        if(file_exists($path)){
            if(!unlink($path)){
                $message->message_("$path 파일이 존재 합니다.","history.back();","exit");   //함수 호출
            }
        }
        if(move_uploaded_file($_FILES[$upfile]['tmp_name'],$path)){//파일를 이동
            @chmod($path, $permision);
            return $path;
        }else{
            $message->message_("$path 파일 저장 실폐.","history.back();","exit");   //함수 호출
        }
    }
}
?>

