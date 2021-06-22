<?
class disk_size extends lib_road{
	function float_len_($value,$len){
		list($d1,$d2)=explode(".",$value);
		if($d2){
			return $d1.".".substr($d2,0,$len);
		}else{
			return $d1;
		}
	}

	function disk_size_($trp,$len){
		if($trp <= 0){
			$trp = "0 Byte";
		}elseif ($trp < 1024) {
			$trp = $this->float_len_($trp,$len)." Byte";
		}elseif ($trp < 1048576) {
			$trp = $trp/1024;
			$trp = $this->float_len_($trp,$len)." KB";
		}elseif ($trp < 1073741824) {
			$trp = $trp/1048576;
			$trp = $this->float_len_($trp,$len)." MB";
		}elseif($trp >= 1073741824){
			$trp = $trp/1073741824;
			$trp = $this->float_len_($trp,$len)." GB";
		}else{
			$trp = "0 Byte";
		}
		return $trp;
	}
}
?>