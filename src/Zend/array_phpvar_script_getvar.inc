<?
class array_phpvar_script_getvar extends lib_road{
	function array_phpvar_script_getvar_($data,$not_code=array()) {
		foreach($data as $key=>$value){
			if(!in_array($key,$not_code) && $value && !stristr($pgdata,"$key=$value&")){
				$pgdata .= $key."=".$value."&";
			}
		}
		return $pgdata;
	}
}
?>