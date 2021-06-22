<?
class image_resize2 extends lib_road{
	function image_resize2_($img_width,$img_height,$max_,$wi_he="width",$max_wh=""){
		if($wi_he=="width"){
			if($img_width > $max_){
				$width = $max_;
				$height = $max_*($img_height/$img_width);
			}else{ //그 이하일경우 원본 사이즈 유지
				$width = $img_width;
				$height= $img_height;
			}
			if($max_wh <= $height and $max_wh){
				$height = $max_wh;
			}
		}else{
			if($img_height > $max_){
				$width = $max_*($img_width/$img_height);
				$height = $max_;
			}else{ //그 이하일경우 원본 사이즈 유지
				$width = $img_width;
				$height= $img_height;
			}
			if($max_wh <= $width and $max_wh){
				$width = $max_wh;
			}
		}
		return array("width"=>intval($width),"height"=>intval($height));
	}
}
?>
