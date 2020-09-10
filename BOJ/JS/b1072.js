// const input = require('fs').readFileSync('/dev/stdin').toString().split('\n');
const input = require('fs').readFileSync('./input.txt').toString().split('\n');

const bs = (left, right, z) => {
  const mid = Math.floor((left + right) / 2); 
  if(left >= right) {
    return mid;
  }
  let tval = Math.floor(((Y + mid) / (X + mid))* 100);
  if(tval > z) {
    return bs(left, mid, z);
  } else {
    return bs(mid+1, right, z);
  }
}

let a = input[0].split(' ');
const X = Number(a[0]);
const Y = Number(a[1]);
const Z = Math.floor((100 * Y / X));
console.log(Y / X);
console.log(100 * Y / X);
console.log(Y / X * 100);
let result = 0;
result = bs(0, 100000000001, Z);
if(result == 100000000001) {
  result = -1;
}
console.log(result);