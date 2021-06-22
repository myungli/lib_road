<?
class window_resize extends lib_road{
	function window_resize_($width,$height,$scroll="y"){
		$script_duplicate_check = $this->lib_hab("script_duplicate_check");
		if($script_duplicate_check->script_duplicate_check_("window_resize")){
			if(!$width || !$height){
				echo("인자(2)가 부족합니다.");
				exit;
			}
			if($scroll == "y"){
				$scroll = "";
			}else{
				$scroll = "hidden";
			}
			$GLOBALS[script]  .= "
		window.resizeTo($width,$height);
		document.body.style.overflow='$scroll';
			";
		}
	}
}
?>