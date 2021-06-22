<?
class dir_file_list_row extends lib_road{
	var $ddata;
	var $i=0;
    function dir_file_list_row_($dir_name,$search="",$order_by="",$r_line="15",$p_line="15",$tip="all_file",$tip2=""){
//$field="f_name,name,exp,dir_name,df_name",
		GLOBAL $rdata;
		if(!is_dir($dir_name)){
			return false;
		}
		$this->dir_list($dir_name,$tip,$tip2);

		if($search){
			$search_multi_array = $this->lib_hab("search_multi_array");
			$rdata = $search_multi_array->search_multi_array_($search);
		}

		$total_record = count($rdata);
		$paging = $this->lib_hab("paging");   //library 로드
		$row_page = $paging->paging_($total_record,$GLOBALS[page],$p_line,$r_line);  //함수 호출

		if($total_record){
			if($order_by){
				$o_name = explode(" ",$order_by);
				$o_tip = array("desc"=>"1","asc"=>"0");
				if($tip=="all_file"){
					$stristr_data = ",f_name,name,exp,dir_name,df_name,reg_date,size,";
				}else{
					$stristr_data = ",f_name,name,exp,dir_name,df_name,";
				}
				if($o_name[0] && $o_name[1] && stristr($stristr_data,",$o_name[0],")){
					$SortMultiArray = $this->lib_hab("SortMultiArray");
					$rdata = $SortMultiArray->SortMultiArray_($o_name[0],$o_tip[$o_name[1]]);
				}
			}
			for($i=$row_page[first]; $i<=$row_page[last]; $i++){
				$rdata[$i][article_num] = $row_page[article_num];
				$row_page[article_num]--;
			}
			$rdata = array_slice($rdata,$row_page[first],$r_line);
		}
		return array($this->ddata,$rdata,$total_record,$row_page);
    }

	function dir_list($dir_name,$tip,$tip2){
		GLOBAL $rdata;
		$handle = opendir($dir_name);
		while (false !== ($file = readdir($handle))) {
			$dir =$dir_name.'/'.$file;
			if(is_dir($dir) && $file != '.' && $file !='..' && $file){
				$this->ddata[] = $dir;
				if($tip=="all_file"){
					$this->dir_list($dir);
				}
			}elseif(is_file($dir) && $file != '.' && $file !='..' && $file){
				$row[f_name] = $file;
				list($row['name'],$row['exp']) = explode(".",$file);
				if($tip2=="datesize"){
					$row[reg_date] = date("Y-m-d H:i:s", fileatime($dir));
					$row['size'] = filesize($dir);
				}
				$row[dir_name] = $dir_name;
				$row[df_name] = $dir;
				$rdata[$this->i++] = $row;
			}
		}
		closedir($handle);
	}
}
?>