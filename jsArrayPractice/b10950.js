let fs = require('fs');
let input = fs.readFileSync('/dev/stdin').toString().split('\n');
// let input = fs.readFileSync('./input.txt').toString().split('\n');

let readlineIdx = 0;
const readInput = () => input[readlineIdx++];

function main() {
  let [N] = readInput().split(' ');
  N = Number(N);
  while(N > 0) {
    N = N - 1;
    let [a, b] = readInput().split(' ');
    a = Number(a);
    b = Number(b);
    console.log(a+b);
  }
}

main();

