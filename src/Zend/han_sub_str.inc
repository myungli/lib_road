<?
class han_sub_str extends lib_road{
	function han_sub_str_($src, $n,$save="...",$var = "") {
		if(!$src){
			return $var;
		}else{
			if (strlen($src) <= $n || !$n || $n<4) {
				return $src;
			} else {
				$tmp = substr($src, 0, $n);
				preg_match('/^([\x00-\x7e]|.{2})*/', $tmp, $res);
				return $res[0].$save;
			}
		}
	}
}
?>