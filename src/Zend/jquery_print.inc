<?
class jquery_print extends lib_road{
    function jquery_print_($script_form_check_function_name="script_form_check",$form_name="",$sub_mit = ""){
		if($form_name){
$query_print = "
function $script_form_check_function_name(){
	var form = document.$form_name;
	$GLOBALS[script_form_echo]
";
			if($sub_mit=="nosubmit"){
$query_print .= "
	return true;
";
			}else{
$query_print .= "
	form.submit();
";
			}
$query_print .= "
}
";
			$GLOBALS[script_form_echo] = "";
		}
		if($this->ver_array[jquery_script] || $print){
echo("
<script language='JavaScript'>
<!--
".$this->ver_array[jquery_script]."
$query_print
//-->
</script>
");
        $this->ver_array[jquery_script] = "";
		}
	}
}
?>