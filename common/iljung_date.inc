<?
class iljung_date extends lib_road{
    function iljung_date_($year,$month,$d_format="Y-n-j",$m_format="Y-n"){
        $date[to_date] = date($d_format);
        list($date[to_year],$date[to_month],$date[to_day]) = explode("-",$date[to_date]);
        if(!$year || !$month){
            $date[year]=$date[to_year];
            $date[month]=$date[to_month];
            $year=$date[to_year];
            $month=$date[to_month];
        }else{
            $date[year]=$year;
            $date[month]=$month;
        }
        $date[end_day] = $this->end_day($year,$month);//이달의 마지막 일자 구하기
        $date[first] = date(w,mktime(0,0,0,$month,1,$year));//1일자 요일 구하기
        list($date[prev_year],$date[prev_month]) = split("-",date($m_format,mktime(0,0,0,$month-1,1,$year)));//1일자 요일 구하기
        list($date[next_year],$date[next_month]) = split("-",date($m_format,mktime(0,0,0,$month+1,1,$year)));//1일자 요일 구하기
        return $date;
    }
    function end_day($year,$month){//$end_mo => 이번달 숫자
        $monthDay = Array(0, 31, 0, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31); // 0월은 없으므로 0
        if ($year % 400 == 0 || $year % 100 != 0 && $year % 4 == 0) {
            $monthDay[2] = 29;
        } else {
            $monthDay[2] = 28;
        }
        return $monthDay[intval($month)];
    }
}
?>