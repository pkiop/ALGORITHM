
const input = require('fs').readFileSync('/dev/stdin').toString().split('\n');
// const input = require('fs').readFileSync('./input.txt').toString().split('\n');

for(let i=1;i<=Number(input[0]);++i) {
  let a = input[i].split(' ');
  let temp = 1;
  for(let j=0;j<Number(a[1]);++j) {
    temp = temp * Number(a[0]);
    temp = temp % 10;
  }
  if(temp == 0) {
    temp = 10;
  }
  console.log(temp);
}
