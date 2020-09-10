const input = require('fs').readFileSync('/dev/stdin').toString().split('\n');
// const input = require('fs').readFileSync('./input.txt').toString().split('\n');

let a = [];
let b = [];
let z;
const bs = (left, right) => {
  const mid = Math.floor((left + right) / 2); 
  if(left > right) {
    return 0;
  }
  let tval = a[mid]; 
  if(tval > z) {
    return bs(left, mid-1);
  } else if(tval < z){
    return bs(mid+1, right);
  } else {
    return 1;
  }
}

for(let i=0;i<Number(input[0]);++i) {
  a = input[i*4+2].split(' ').map(x => parseInt(x));
  b = input[i*4+4].split(' ').map(x => parseInt(x));
  a.sort();
  for(const v of b) {
    z = v;
    console.log(bs(0, Number(input[i*4+1]-1)));
  }
}