<?
class ajax_layer_pop extends lib_road{
	function ajax_layer_pop_($id,$type,$url,$data,$dataType,$trfal,$error,$lay,$lay2,$bg){
		echo"
	<style>
		$lay{
  display:none;
  position:fixed;
  top:0; left:0;
  width:100%; height:100%;
  z-index:100;
}
$lay $bg{
  position:fixed;
  top:0; left:0;
  width:100%; height:100%;
  background:#000;
  opacity:.5;
  filter:alpha(opacity=50);
}
		
$lay $lay2 {display:block;}
$lay2 {
     position: absolute;height:auto;
     top: 500px; left: 50%;
     background-color:#fff;
     transform:translate(-50%, -50%);
     z-index: 10;}
		</style>
		";
		
		$GLOBALS[script] .= "
				$(function(){
  //var formdata = jQuery('form[name='myform']').serialize();
  $('$id').click(function(){
    //var no = $(this).attr('value');
    $('html, body').css({'overflow': 'hidden'});
    $.ajax({
      type: '$type' , 
      url: '$url',
      data : $data,
      dataType : '$dataType' ,
      async:$trfal,
      error : function(xml){
        alert('$error');
        },
      success: function(data) {
      var bg2 = '$bg';
      var bg3 = bg2.split('.');
      var bg4 = bg3[1];
      	var bg = $('$lay2').prev().hasClass(bg4);
      	if(bg){
      		$('$lay').fadeIn();
      	}else{
      	  $('$lay2').fadeIn();
      	}
      		$('$lay $bg').click(function(e){	//배경을 클릭하면 레이어를 사라지게 하는 이벤트 핸들러
      			$('$lay').fadeOut();
      			e.preventDefault();
      			$('html, body').css({'overflow': 'visible'});
      		});
          
         $('$lay2').html(data);
        }
     }); 
   })
})
				";
		

	}
}

?>