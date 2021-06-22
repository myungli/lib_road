<?
class dir_chk extends lib_road{
    function dir_chk_($dir,$permision){
        if (!file_exists($dir)){
            if(!mkdir($dir,$permision)){
                $lib->lib_hab("message");   //라이브러리 로드
                $message->message_("디렉토리를 만들수 없습니다. Check Permissions!!","history.back();","exit");   //함수 호출
             }
        }
    }
}
?>