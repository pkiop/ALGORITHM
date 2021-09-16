let fs = require('fs');
let input = fs.readFileSync('./Ainput.txt').toString().split('\n');

let readlineIdx = 0;
const readInput = () => input[readlineIdx++];

function solution(N) {
  let bPositive = N >= 0 ? true : false;
  let nString = '';
  if (bPositive === false) {
    N = N * -1;
  }
  nString = String(N);
  let answer = '';
  for (let i = 0; i < nString.length; i++) {
    if (bPositive) {
      if (nString[i] < '5') {
        return nString.slice(0, i) + '5' + nString.slice(i);
      }
    } else {
      if (nString[i] > '5') {
        return '-' + nString.slice(0, i) + '5' + nString.slice(i);
      }
    }
  }

  if (bPositive) {
    return nString + '5';
  } else {
    return '-' + nString + '5';
  }
}

function main() {
  while (true) {
    let a = readInput();
    if (a === "-999999") {
      return;
    }
    console.log(solution(a));
  }
}
main();

