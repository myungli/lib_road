<?
class value_check extends lib_road{
    function value_check_($var_arr,$var_cou_arr) {
		if(count($var_arr)>=1 && is_array($var_arr)){
			foreach($var_arr as $value){
				if(!$value){
					return false;
				}
			}
		}
        if(count($var_cou_arr)>=1 && is_array($var_cou_arr)){
            foreach($var_cou_arr as $value){
                if(count($value) < 1){
                    return false;
                }
            }
        }
        return true;
    }
}
?>