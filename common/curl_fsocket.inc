<?
class curl_fsocket extends lib_road{//curl 서버 라이브러리 만들어 져야 사용가능함.
    function curl_fsocket_($url, $method='GET'){
        $ch = curl_init();
		$info = parse_url($url);
		$url = $info['scheme'] . '://' . $info['host'] . $info['path'];
		switch(strtoupper($method)){
			case 'GET':
				curl_setopt($ch, CURLOPT_URL, "$url");//접속할 URL 주소
				curl_setopt($ch, CURLOPT_POST, FALSE); // Post Get 접속 여부
				break;
            case 'POST':
				curl_setopt($ch, CURLOPT_URL, "$url");//접속할 URL 주소
				curl_setopt($ch, CURLOPT_POST, TRUE); // Post Get 접속 여부
				break;
            default:
				return FALSE;
        }

        curl_setopt($ch, CURLOPT_POSTFIELDS, "$info[query]");// Post 값 Get 방식처럼적는다.
        curl_setopt($ch, CURLOPT_RETURNTRANSFER, TRUE);// 결과값을 받을것인지
		
		if($info['scheme']=="https"){
			//curl_setopt($ch, CURLOPT_SSL_VERIFYHOST, TRUE);
			//curl_setopt($ch, CURLOPT_SSL_VERIFYPEER, TRUE);
			curl_setopt($ch, CURLOPT_SSL_VERIFYHOST, 3);// SSL 버젼 (https 접속시에 필요)
			curl_setopt($ch, CURLOPT_SSL_VERIFYPEER, FALSE);// 인증서 체크같은데 TRUE 시 안되는 경우가 많다.CURLOPT_SSL_VERIFYPEER
		}

        //curl_setopt($ch, CURLOPT_CONNECTTIMEOUT, 60);//연결 시도를 기다릴 초. 0은 영원히 기다릴 것을 의미합니다
        curl_setopt($ch, CURLOPT_TIMEOUT, 60);//  cURL 함수의 실행에 걸린 시간의 최대값입니다.

		//curl_setopt($ch, CURLOPT_HEADER, FALSE);//헤더값을 가져오기위해 사용합니다. 쿠키를 가져올때사용합니다.
		$header = array(
        "Accept: text/xml,application/xml,application/xhtml+xml,text/html;q=0.9,text/plain;q=0.8,image/png,*/*;q=0.5",
        "Accept-Language: ru-ru,ru;q=0.7,en-us;q=0.5,en;q=0.3",
        "Accept-Charset: windows-1251,utf-8;q=0.7,*;q=0.7",
        "Keep-Alive: 300");
		//curl_setopt($ch, CURLOPT_HTTPHEADER, array("cache-control: no-cache","content-type: application/x-www-form-urlencoded"));//
		curl_setopt($ch, CURLOPT_HTTPHEADER, $header);//

        curl_setopt($ch, CURLOPT_REFERER, $url);//HTTP 요청에서 사용되는 "Referer :" 헤더의 내용.
        $agent = 'Mozilla/5.0 (compatible; MSIE 9.0; Windows NT 6.0; Trident/5.0)';
		//$agent = "Mozilla/4.0 (compatible; MSIE 5.01; Windows NT 5.0)";
        curl_setopt($ch, CURLOPT_USERAGENT, $agent);//HTTP 요청에서 사용되는 "User - Agent :" 헤더의 내용
//$httpCode = curl_getinfo($ch, CURLINFO_HTTP_CODE);
//print_r(get_headers($url, 1));
//echo("curl_res: $httpCode <br>");
//exit;
		$res = curl_exec($ch);

		$curl_res = curl_errno($ch);
		$curl_err = curl_error($ch);

        curl_close($ch);
		if ($curl_res == "OK"){
			//echo $curl_err."($curl_res)\n";
			//exit;
			return $res;
		}else{
		//echo("curl_res2: $curl_res <br>");
			echo $curl_err."($curl_res)\n";
			return FALSE;
		}
    }
}
?>