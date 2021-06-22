<?
class jumin_resnocheck extends lib_road{
	function jumin_resnocheck_($resno1,$resno2) {
	  $resno = $resno1.$resno2;

	  // 형태 검사: 총 13자리의 숫자, 7번째는 1..4의 값을 가짐
	  if (!ereg('^[[:digit:]]{6}[1-4][[:digit:]]{6}$', $resno)){
		return false;
	  }
	  // 날짜 유효성 검사
	  $birthYear = ('2' >= $resno[6]) ? '19' : '20';
	  $birthYear += substr($resno, 0, 2);
	  $birthMonth = substr($resno, 2, 2);
	  $birthDate = substr($resno, 4, 2);
	  if (!checkdate($birthMonth, $birthDate, $birthYear)){
		return false;
	  }
	  // Checksum 코드의 유효성 검사
	  for ($i = 0; $i < 13; $i++) $buf[$i] = (int) $resno[$i];
	  $multipliers = array(2,3,4,5,6,7,8,9,2,3,4,5);
	  for ($i = $sum = 0; $i < 12; $i++) $sum += ($buf[$i] *= $multipliers[$i]);
	  if ((11 - ($sum % 11)) % 10 != $buf[12]){
		return false;
	  }
	  // 모든 검사를 통과하면 유효한 주민등록번호임
	  return true;
	}
}