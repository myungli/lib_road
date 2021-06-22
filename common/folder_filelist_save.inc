<?
class folder_filelist_save extends lib_road{
	var $list2,$tip2,$f_ext;
	function folder_filelist_save_($dir,$tip="file",$log_name="folder_fd_list.txt",$tip2="subno",$f_ext=""){
		$this->tip2 = $tip2;
		$this->f_ext = $f_ext;
		if(!is_dir($dir)){
			return false;
		}
		$this->list2 = array();
		$dir_size = $this->list_return($dir,$tip);
		$f_write2 = $this->lib_hab("f_write2");
		$f_write2->f_write2_("$dir/$log_name",join("\n",$this->list2));
	}

	function list_return($dir,$tip){
		$dir_size = 0;
		$handle = opendir($dir);
		while ($file = readdir($handle)) {
			if ($file != "." and $file != "..") {
				if(is_file("$dir/$file") and eregi("file",$tip)){
					if(!$this->f_ext){
						$f_size = filesize("$dir/$file");
						$this->list2[] = "File\t".urldecode($file)."\t"."$dir/$file"."\t".$f_size."\t".date("Y-m-d H:i:s",filemtime("$dir/$file"));
						$dir_size += $f_size;
					}else{
						if(stristr($this->f_ext,strstr($file,"."))){
							$f_size = filesize("$dir/$file");
							$this->list2[] = "File\t".urldecode($file)."\t"."$dir/$file"."\t".$f_size."\t".date("Y-m-d H:i:s",filemtime("$dir/$file"));
							$dir_size += $f_size;
						}
					}
				}else{
					if(is_dir("$dir/$file") and eregi("dir",$tip)){
						if($this->tip2=="subok"){
							$dir_size = $this->list_return("$dir/$file",$tip);
						}
						$this->list2[] = "Dir\t".urldecode($file)."\t"."$dir/$file"."\t".$dir_size."\t".date("Y-m-d H:i:s",filemtime("$dir/$file"));
					}
				}
			}
		}
		closedir($handle);
		return $dir_size;
	}
}
?>