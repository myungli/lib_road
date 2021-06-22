<?
class ftp_upload_connect extends lib_road{
    var $ftp_home_dir;
    var $fc;
    function ftp_upload_connect_($host,$user,$pass,$port,$ftp_home_dir){
        $this->ftp_home_dir = $ftp_home_dir;
        $this->fc = ftp_connect($host,$port,4);
		if(!$this->fc){
			return "no";
		}
        $fl = ftp_login($this->fc,$user,$pass);
		ftp_set_option($this->fc, FTP_TIMEOUT_SEC, 60);//FTP_BINARY,FTP_ASCII
        if($fl){
            return "ok";
        }else{
            return "no";
        }
    }

    function ftp_upload_quit_() {
        if($this->fc){
            ftp_quit($this->fc);
        }
    }

    function ftp_upload_dir_save_($o_f_dir,$ch_mod){
        $dir = split("/",$o_f_dir);
        $fd1 = ftp_chdir($this->fc, $this->ftp_home_dir);
        foreach($dir as $value){
            if($value){
				if(!@ftp_chdir($this->fc, $value)){
					ftp_mkdir($this->fc, $value);
					ftp_site($this->fc, sprintf('CHMOD %u %s', $ch_mod, $value));
					ftp_chdir($this->fc, $value) or DIE('디렉토리 이동 실패 ( '.$value.' )');
				}
            }
        }
    }

    function ftp_dir_upload_($o_dir,$o_f_dir,$ch_mod) {
        $this->ftp_upload_dir_save_($o_f_dir,$ch_mod);
		if ($handle = opendir($o_dir)) {
			$i = 0;
			while ($file = readdir($handle)) {
				if ($file != "." && $file != "..") {
					$fp = fopen("$o_dir/$file","r");
					if(ftp_fput($this->fc, $file, $fp, FTP_BINARY)){
                        ftp_site($this->fc, sprintf('CHMOD %u %s', $ch_mod, $file));
                        $ok_f[]=$file;
                    }else{
                        $err_f[]=$file;
                    }
					fclose($fp);
				}
			}
			closedir($handle);
		}
        return array($ok_f,$err_f);
    }

    function ftp_upload_file_ftp_($o_f_dir,$o_fns,$o_f_n,$ch_mod) {
        $this->ftp_upload_dir_save_($o_f_dir,$ch_mod);
        $i=0;
        foreach($o_fns as $upfile){
            if($_FILES[$upfile]['name'] || file_exists($_FILES[$upfile]['tmp_name'])){
                $fp = fopen($_FILES[$upfile]['tmp_name'],"r");
				$a = strstr($o_f_n[$i],".");
				if(!$a){
					$a = strstr($_FILES[$upfile]['name'],".");
					$o_f_n[$i] = $o_f_n[$i].$a;
				}
                if(ftp_fput($this->fc, $o_f_n[$i], $fp, FTP_BINARY)){
                    ftp_site($this->fc, sprintf('CHMOD %u %s', $ch_mod, $o_f_n[$i]));
                    $ok_f[]=$o_f_n[$i];
                }else{
                    $err_f[]=$_FILES[$upfile]['name'];
                }
    			fclose($fp);
            }else{
                $err_f[]=$_FILES[$upfile]['name'];
            }
            $i++;
        }
        return array($ok_f,$err_f);
    }

    function ftp_file_ftp_($o_f_n,$o_f_dir,$save_file_name,$ch_mod) {
        $this->ftp_upload_dir_save_($o_f_dir,$ch_mod);
        $fp = fopen($o_f_n,"r");
        if(ftp_fput($this->fc, $save_file_name, $fp, FTP_BINARY)){
            ftp_site($this->fc, sprintf('CHMOD %u %s', $ch_mod, $save_file_name));
            $ok_f=$save_file_name;
        }else{
            $err_f=$save_file_name;
        }
        fclose($fp);
        return array($ok_f,$err_f);
    }
}
?>