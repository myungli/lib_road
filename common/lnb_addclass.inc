<?php
class lnb_addclass extends lib_road
{
    function lnb_addclass_( $selector, $index )
    {
		echo 
		"
		<script>
			$(function(){
				$('$selector').eq($index).addClass('on');
			});		
		</script>
		"
		;
    }

}

?>
