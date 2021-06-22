<?
class image_resize extends lib_road{
	function image_resize_($img_width,$img_height,$max_width,$max_height){
		if($img_width > $max_width || $img_height > $max_height){
			if($img_width == $img_height){//원본과 썸네일의 가로세로비율이 같은경우
				$width = $max_width;
				$height = $max_height;
			}else if($img_width < $img_height){//세로에 기준을 둔경우
//				$width = $img_width*$max_height/$img_height;
				$width = $max_width*($img_width/$img_height);
				$height = $max_height;
			}else{//가로에 기준을 둔경우
				$width = $max_width;
//				$height = $img_height*$max_width/$img_width;
				$height = $max_height*($img_height/$img_width);
			}
		}else{ //그 이하일경우 원본 사이즈 유지
			$width = $img_width;
			$height= $img_height;
		}
		return array("width"=>ceil($width),"height"=>ceil($height));
	}
}
?>
