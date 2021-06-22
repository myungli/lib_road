<?
class file_ctype_return extends lib_road{
	function file_ctype_return_($str) {
		switch( $str ) {
			case "pdf": $ctype="application/pdf"; break;
			case "exe": $ctype="application/octet-stream"; break;
			case "zip": $ctype="application/zip"; break;
			case "doc": $ctype="application/msword"; break;
			case "csv":
			case "xls": $ctype="application/vnd.ms-excel"; break;
			case "ppt": $ctype="application/vnd.ms-powerpoint"; break;
			case "gif": $ctype="image/gif"; break;
			case "png": $ctype="image/png"; break;
			case "jpeg":
			case "jpg": $ctype="image/jpg"; break;
			case "mp3": $ctype="audio/mpeg"; break;
			case "wav": $ctype="audio/x-wav"; break;
			case "mpeg":
			case "mpg":
			case "mpe": $ctype="video/mpeg"; break;
			case "mov": $ctype="video/quicktime"; break;
			case "avi": $ctype="video/x-msvideo"; break;

//The following are for extensions that shouldn't be downloaded (sensitive stuff, like php files)
//			case "txt": die("<b>Cannot be used for ". $file_extension ." files!</b>"); break;
//			case "php": $ctype="text/html; charset=utf-8'";
//			case "htm":
//			case "html":
//			case "txt": $ctype="application/txt"; break;
			case "txt": $ctype="text/html; charset=utf-8'"; break;

			default: $ctype="application/force-download";
		}

		return $ctype;
	}
}
?>