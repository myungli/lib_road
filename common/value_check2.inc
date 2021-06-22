<?
class value_check2 extends lib_road{
    function value_check2_($var_arr) {
		if(count($var_arr)>=1 && is_array($var_arr)){
			foreach($var_arr as $value){
				if(is_array($value)){
					if(count(array_filter($value))<1){
						return false;
					}
				}else{
					if(!$value){
						return false;
					}
				}
			}
			return true;
		}else{
			return false;
		}
    }
}
?>