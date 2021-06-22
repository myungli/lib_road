<?
class javascript extends lib_road {
    var $html_header   = "<html><head>";
    var $script_header = "<script type='text/javascript'>\n";
    var $script_body   = array();
    var $script_footer = "</script>\n";
    var $html_footer   = "</head><body></body></html>";

    function javascript() {

    }

    function add($script="") {
        array_push($this->script_body, $script."\n");
    }

    function execute($isBody=FALSE) {
        if ($isBody) {
            print $this->html_header;
        }
        print $this->script_header;
        if (is_array($this->script_body)) {
            foreach ($this->script_body as $body) {
                print $body;
            }
        }
        print $this->script_footer;
        if ($isBody) {
            print $this->html_footer;
        }
    }

}
?>