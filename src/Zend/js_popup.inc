<?
class js_popup extends lib_road {
    /**
     * 일반 창
     * @params string, integer, integer, string, string
     * @return string
     * @since 2010-04-02
     */
    function js_popup_($url, $width, $height, $style="", $name="") {
        $result = <<<TEXT
        function topPosition() {
            return typeof window.pageYOffset != 'undefined' ? window.pageYOffset : document.documentElement && document.documentElement.scrollTop ? document.documentElement.scrollTop : document.body.scrollTop ? document.body.scrollTop : 0;
        }

        function leftPosition() {
            return typeof window.pageXOffset != 'undefined' ? window.pageXOffset : document.documentElement && document.documentElement.scrollLeft ? document.documentElement.scrollLeft : document.body.scrollLeft ? document.body.scrollLeft : 0;
        }

        var name = '$name';
        if (!name) { name = 'winPop'; }

        if (dojo.isIE) { paramHeight -= 0; }
        var nPosX = (screen.availWidth - $width) / 2;
        var nPosY = (screen.availHeight - $height) / 2;

        var style = '$style';
        if (style) {
            if (style.indexOf('scrollbars') == -1) {
                style += ',scrollbars=no';
            }
        }
        
        var url = '$url';
        var popupWindow = window.open(url
                                     ,name
                                     ,'top=' + nPosY +',left=' + nPosX +',width=$width,height=$height,toolbar=no,location=no,directories=no,status=no,menubar=no,resizable=no,copyhistory=no,$style'
                                     );
        popupWindow.focus();
TEXT;
        return $result;
    }

    /**
     * 모달 창
     * @params string, integer, integer, string, string
     * @return string
     * @since 2010-04-02
     */
    function open_modal_($url, $width, $height, $style="", $params="") {
        if ($style) {
            if (substr($style, strlen($style)-1) != ";") $style .= ";";
        } else {
            $style = "";
        }
        if (!$params) {
            $params = "document";
        }

        $result = <<<TEXT
        var url    = '$url';
        var style  = '$style';
        var params = $params;
        
        return window.showModalDialog(url, params, 'dialogWidth:${width}px; dialogHeight:${height}px; status:0; center:1; help:0; dialogHide:0; $style');

TEXT;
        return $result;
    }

    /**
     * 팝업 열기 (익스프로러일때 모달창 기타 브라우저일때 일반창)
     * @params string, integer, integer, string, string
     * @return string
     * @since 2010-04-02
     */
    function open_window_($url, $width, $height, $style="", $params="", $name="") {
        $js_open_modal  = $this->open_modal_($url, $width, $height, $style, $params);
        $js_open_window = $this->js_popup_($url, $width, $height, $style, $params);
        $result = <<<TEXT
        if (dojo.isIE) {
            $js_open_modal
        } else {
            $js_open_window
        }
TEXT;
        return $result;
    }
}
?>