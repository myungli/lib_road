<?
class global_value_return extends lib_road{
    function global_value_return_(){
		if($_SERVER[REQUEST_METHOD] == "POST"){
			return $_POST;
		}else{
			return $_GET;
		}
    }
}
?>