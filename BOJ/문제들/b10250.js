
// const input = require('fs').readFileSync('/dev/stdin').toString().split('\n');
const input = require('fs').readFileSync('./b10250.txt').toString().split('\n');

let first = false;

const solution = input2 => {
  const input = input2.split(' ');
  let col = parseInt(parseInt(input[2]) / parseInt(input[0]));
  let row = parseInt(input[2]) - col * parseInt(input[0]);
  if(row == 0) {
    row = parseInt(input[0]); 
    col-=1;
  }
  let ans = String(row);
  if(col+1< 10) {
    ans += '0';
  }
  ans += String(col+1);
  console.log(ans);
  return;
}

for(const a of input) {
  if(first == false) {
    first = true;
    continue;
  }

  solution(a);
}

