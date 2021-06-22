<?
class header_print extends lib_road{
    function header_print_($action,$type){
        if($type=="status"){
            $header_arr = array("not"=>"HTTP/1.0 404 Not Found");
            header($header_arr[$action]);
            exit;
        }elseif($type=="location"){
            //header("Location: $action");
			header('Cache-Control: no-cache, no-store, must-revalidate'); // HTTP 1.1. 사용시 캐시 제거
			header('Pragma: no-cache'); // HTTP 1.0. 사용시 캐시 제거
			header('Expires: 0'); // Proxies. 캐시 만료 시간 작성 if, arg == 0, 이미 만료된 캐시
			header("Location: " . $action, TRUE, 301); // 새로운 URL로 현재 페이지를 301 redirect
			//header("Location: $action,TRUE,301");
            exit;
        }else{
			$_SESSION = array();
			header('HTTP/1.0 404 Not Found');
			exit;
		}
    }
}
?>