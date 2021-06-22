<?php


class curl extends lib_road
{

	//http 연결
    function http_curl_($url)
    {
		$ch = curl_init();
		curl_setopt($ch, CURLOPT_URL,$url); 
		//curl_setopt($ch,CURLOPT_HTTPHEADER,array('Accept: application/variant_div(left, right).epg.vrt.be.playlist_1.1+xml')); 
		curl_setopt($ch, CURLOPT_FAILONERROR,1); 
		curl_setopt($ch, CURLOPT_FOLLOWLOCATION,1); 
		curl_setopt($ch, CURLOPT_RETURNTRANSFER,1); 
		curl_setopt($ch, CURLOPT_TIMEOUT, 15); 
		$data = curl_exec($ch);
		curl_close($ch);

		return $data;
    } // http_curl_

	//https 연결
    function https_curl_($url,$postfields = array())
    {
		 $ch = curl_init(); 
		 curl_setopt($ch, CURLOPT_URL, $url); 

		 curl_setopt($ch, CURLOPT_SSL_VERIFYPEER, FALSE);  // 인증서 체크같은데 true 시 안되는 경우가 많다.
		 curl_setopt($ch, CURLOPT_SSL_VERIFYHOST, 0); 
		 curl_setopt($ch, CURLOPT_HEADER, 0); //헤더값을 가져오기위해 사용합니다. 쿠키를 가져오려고요.
		 curl_setopt($ch, CURLOPT_USERAGENT, $_SERVER['HTTP_USER_AGENT']);  //Mozilla/4.0 (compatible; MSIE 5.01; Windows NT 5.0)
		 curl_setopt($ch, CURLOPT_RETURNTRANSFER, 1); // 결과값을 받을것인지
		 curl_setopt($ch, CURLOPT_POST, 1); // Post Get 접속 여부
		 curl_setopt($ch, CURLOPT_POSTFIELDS, $postfields); // Post 값 Get 방식처럼적는다.

		 $data = curl_exec($ch); 
		 if (curl_error($ch))  
		 { 
			exit('CURL Error('.curl_errno( $ch ).') '.curl_error($ch)); 
		 } 
		 curl_close($ch); 

		 return $data;
    } // https_curl_

}

?>
