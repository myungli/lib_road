<?php
class change_img extends lib_road{
	function write_binary_file($type){
	echo("
<script>
write_binary_file = function(url) {
  // 49 => '1' (decimal)
  var filestream = load_url(url);
  var bytes = [];
  for (i = 0; i < filestream.length; i++)
	bytes[i] = filestream.charCodeAt(i) & 0xff;
  return 'data:image/$type;base64,'+base64(String.fromCharCode.apply(String, bytes));
}
load_url = function(url) {
	var req = new XMLHttpRequest();
	req.open('GET',url,false);
	req.overrideMimeType('text/plain; charset=x-user-defined');
	req.send(null);
	if (req.status != 200) return '';
	return req.responseText;
}
function base64(s) {
    var key = 'ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789+/=';
    var i = 0, len = s.length,
      c1, c2, c3,
      e1, e2, e3, e4,
      result = [];
    
    while (i < len) {
        c1 = s.charCodeAt(i++);
        c2 = s.charCodeAt(i++);
        c3 = s.charCodeAt(i++);
        
        e1 = c1 >> 2;
        e2 = ((c1 & 3) << 4) | (c2 >> 4);
        e3 = ((c2 & 15) << 2) | (c3 >> 6);
        e4 = c3 & 63;
        
        if (isNaN(c2)) {
          e3 = e4 = 64;
        } else if (isNaN(c3)) {
          e4 = 64;
        }
        result.push(e1, e2, e3, e4);
    }
    return result.map(function (e) { return key.charAt(e); }).join('');
}
</script>
");
	}
}
?>