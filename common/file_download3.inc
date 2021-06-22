<?
class file_download3 extends lib_road
{

    function file_download3_( $upfile, $upfile_path, $err_script = "", $down_file = "",$str2="")
    {
        if ( $_SERVER[HTTPS] == "on" )
        {	
			
            $page_trans_return = $this->lib_hab( "page_trans_return" );
			$last_url = $page_trans_return->page_trans_return_();
            $new_url = "http://$_SERVER[SERVER_NAME]$_SERVER[PHP_SELF]?".$last_url;

            $header_print = $this->lib_hab( "header_print" );
            $header_print->header_print_( $new_url, "location" );
            exit();
        }

        $message = $this->lib_hab( "message" );
        if ( !$upfile )
        {
            $message->message_( "지정된 파일이 없습니다.", $err_script, "exit" );
        }
        $f_str = ".php,.php3,.phtml,.inc,.pl,.cgi,.asp,.htm,.html";
        $str = strtolower( substr( strrchr( $upfile, "." ), 1 ) );
        if ( !$str )
        {
            $str = "txt";
        }
        if ( stristr( $f_str, $str ) === TRUE )
        {
            $message->message_( "선택하신 파일은 다운로드가 금지된 파일 입니다.", $err_script, "exit" );
        }
        $downloadPath = "$upfile_path/$upfile";
		
		$ch = curl_init($downloadPath);
		curl_setopt($ch, CURLOPT_NOBODY, true);
		curl_exec($ch);
		$retcode = curl_getinfo($ch, CURLINFO_HTTP_CODE);
        if ( $retcode == 404)
        {
            $message->message_( "파일이 없거나 정상적인 파일이 아닙니다.", $err_script, "exit" );
        }
        if ( $down_file )
        {
            $upfile = $down_file.".".$str;
        }
		if($str2 && $down_file){
			$upfile = $down_file.".".$str2;
		}else if(!$down_file && $str2){
			$upfile = $upfile.".".$str2;
		}
        $file_ctype_return = $this->lib_hab( "file_ctype_return" );
        $ctype = $file_ctype_return->file_ctype_return_( $str );
		$size = strlen(file_get_contents($downloadPath));
        header( "Pragma: public" );
        header( "Expires: 0" );
        header( "Cache-Control: must-revalidate, post-check=0, pre-check=0" );
        header( "Cache-Control: public" );
        header( "Content-Description: File Transfer" );
        header( "Content-Type: {$ctype}" );
        $header = "Content-Disposition: attachment; filename=".$upfile.";";
        header( $header );
        header( "Content-Transfer-Encoding: binary" );
        header( "Content-Length: ".$size );
        $fp = @fopen( $downloadPath, "r" );
        while ( $data = @fread( $fp, $size ) )
        {
            echo $data;
        }
        @fclose( $fp );
    }



}

?>
