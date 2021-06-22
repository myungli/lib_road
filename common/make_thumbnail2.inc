<?
class make_thumbnail2 extends lib_road{
	function make_thumbnail2_($imgname,$path,$f_str,$img_size_list,$imginfo,$image_quality='75',$sumine="",$text="",$text_image="text"){//원본이미지, 저장경로, 생성될파일명str, 사이즈리스트,퀄리티,확장자(.gif)
		$image_resize2 = $this->lib_hab("image_resize2");
		if(!$sumine){
			$sumine = end(explode(".",$imgname));
		}
		switch($imginfo[mime]){
			case "image/gif" :
//				echo("aaaa1\n");
//				print_r($tempinfo);
				$im = ImageCreateFromGIF($imgname);
				$imgname = str_replace(array("(",")"," "),array("\(","\)","\ "),$imgname);
				exec("gifsicle -I $imgname", $tempinfo); //gifsicle rpm이 설치되어있어야 한다.
//				$join_gif = join(" " , $tempinfo);
				break;
			case "image/jpeg" :
				$im = imagecreatefromjpeg($imgname); /* Attempt to open */
				break;
			case "image/png" :
				$im = imagecreatefrompng($imgname); /* Attempt to open */
				break;
			case "image/vnd.wap.wbmp" :
				$im = imagecreatefromwbmp($imgname); /* Attempt to open */
				break;
			default : //이외 포맷들은 리턴!
				return false;
		}
		if(is_file($text) && $text_image=="image"){
			$imginfo2 = getimagesize($text);
		}
		if(!$im){ /* 실패시 오류 메세지 이미지로 대체 */
			return false;
		}else{
			foreach($img_size_list as $key => $XYsize){
//				if($imginfo[0] >= $XYsize){
				$size_result = $image_resize2->image_resize2_($imginfo[0],$imginfo[1],$XYsize,"width"); //원본 가로, 원본 세로, 최대 가로, 최대 세로
//echo("bbb : $join_gif : $tempinfo[4]<br>");
				if(eregi('loop forever|loop count', $tempinfo[4])){
					exec("gifsicle --resize $size_result[width]x$size_result[height] $imgname > $path/$f_str$key$sumine");//퍼미션 변경가능 여부를 가지고 썸네일 생성 실패 판단
//echo("aaaa2 : gifsicle --resize $size_result[width]x$size_result[height] $imgname > $path/$f_str$key$sumine<br>\n");
				}else{
					$dst_img = imagecreatetruecolor($size_result[width], $size_result[height]); //타겟이미지를 생성(공이미지)
					imagecopyresampled($dst_img, $im, 0, 0, 0, 0, $size_result[width], $size_result[height], $imginfo[0], $imginfo[1]); //공이미지에 원하는 사이즈의 이미지를 저장
					if($text && $text_image=="text"){
						$text_s = 9;
						$xwidth_ = ceil($size_result[width]-(strlen($text)+2)*9);
						$yheight_ = ceil($size_result[height]-9*2);
						if($xwidth_>20 && $yheight_<$size_result[height]){
							$bgc = imagecolorallocate($dst_img, 255, 255, 255);
							$tc  = imagecolorallocate($dst_img, ox00, ox00, oxCC);
							imagefilledrectangle($dst_img,  $xwidth_, $yheight_, $size_result[width], $size_result[height],$bgc);//Output an errmsg
							imagestring($dst_img, $text_s, $xwidth_, $yheight_, " ".$text." ", $tc);//메세지 입력 부분
						}
					}elseif(is_file($text) && $text_image=="image"){
						if($size_result[width]>$imginfo2[0]*2 && $size_result[height]>$imginfo2[1]*4){
							if($imginfo2[mime]=="image/gif"){
								$im2 = ImageCreateFromGIF($text);
							}else{
								$im2 = imagecreatefromjpeg($text);
							}
							imageCopyMerge($dst_img,$im2,$size_result[width]-$imginfo2[0],$size_result[height]-$imginfo2[1],0, 0,$imginfo2[0], $imginfo2[1], $image_quality);
						}
					}

					ImageInterlace($dst_img);
					switch($imginfo[mime]){
						case "image/gif" :
							ImageGif($dst_img,$path."/".$f_str.$key.$sumine);
							break;
						case "image/jpeg" :
							ImageJPEG($dst_img,$path."/".$f_str.$key.$sumine,$image_quality); //실제로 이미지파일을 생성합니다
							break;
						case "image/png" :
							Imagepng($dst_img,$path."/".$f_str.$key.$sumine);
							break;
						case "image/vnd.wap.wbmp" :
							Imagewbmp($dst_img,$path."/".$f_str.$key.$sumine);
							break;
						default : //이외 포맷들은 리턴!
							return false;
					}
					ImageDestroy($dst_img); //메모리 정리
				}
//				}else{
//					copy($imgname,$path."/".$f_str.$key.$sumine);
//				}
			}
			ImageDestroy($im); //메모리 정리
		}
	}
}
?>