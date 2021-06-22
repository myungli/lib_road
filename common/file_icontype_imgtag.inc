<?
class file_icontype_imgtag extends lib_road{
	function file_icontype_imgtag_($filename,$dir='./img'){
		if(eregi("\.gif$|\.jpg$|\.jpeg$",$filename)){
			return "<img src='$dir/icon_img.gif' border='0'>";
		}else if(eregi("\.hwp$",$filename)){
			return "<img src='$dir/icon_hwp.gif' border='0'>";
		}else if(eregi("\.xls$",$filename)){
			return "<img src='$dir/icon_xls.gif' border='0'>";
		}else if(eregi("\.ppt$",$filename)){
			return "<img src='$dir/icon_ppt.gif' border='0'>";
		}else if(eregi("\.pdf$",$filename)){
			return "<img src='$dir/icon_pdf.gif' border='0'>";
		}else if(eregi("\.doc$",$filename)){
			return "<img src='$dir/icon_doc.gif' border='0'>";
		}else if(eregi("\.mp3$|\.wav$|\.mpe$|\.mpg$|\.mpeg$|\.aif$|\.aiff$",$filename)){
			return "<img src='$dir/icon_midi.gif' border='0'>";
		} else if(eregi("\.swf$|\.flv$", $filename)) {
			return "<img src='$dir/swf.gif' border='0'>";
		}else{
			return "<img src='$dir/icon_file.gif' border='0'>";
		}
	}
}
?>