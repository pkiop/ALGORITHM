function solution(n) {
  var answer = '';
  let tempans = Array();
  while(n > 0) {
    tempans.push(n % 3);
    n = Math.floor(n / 3);
  }
  for(let i=0;i<tempans.length-1;++i) {
    if(tempans[i] <= 0) {
    tempans[i] += 3;
    tempans[i+1]--;
    } 
  }
      
  tempans.reverse()
    .forEach((el) => {
      if(el === 0) {
        return;
      }
      if(el === 3) {
        answer += '4';
        return;
      } 
      answer += el;
    })
  return answer;
}