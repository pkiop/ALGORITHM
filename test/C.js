let fs = require('fs');
let input = fs.readFileSync('./Cinput.txt').toString().split('\n');

let readlineIdx = 0;
const readInput = () => input[readlineIdx++];

function isAdjacent(a, b) {
  if (a === 'A' && b === 'B') return true;
  if (a === 'C' && b === 'D') return true;
  if (a === 'B' && b === 'A') return true;
  if (a === 'D' && b === 'C') return true;
  return false;
}

function solution(S) {
  let recodeLeftStack = new Array();
  recodeLeftStack.push(0);
  let removedList = new Array(250001).fill(0);
  for (let i = 1; i < S.length; i++) {
    let recodeLeftStackTop = recodeLeftStack[recodeLeftStack.length - 1];

    if (isAdjacent(S[recodeLeftStackTop], S[i])) {
      removedList[recodeLeftStackTop] = 1;
      removedList[i] = 1;
      recodeLeftStack.pop();
      if (recodeLeftStack.length === 0) {
        recodeLeftStack.push(i + 1);
      }
    } else {
      recodeLeftStack.push(i);
    }
  }
  let answer = '';
  for (let i = 0; i < S.length; ++i) {
    if (removedList[i] === 0) {
      answer += S[i];
    }
  }
  return answer;
}

function main() {

  while (true) {
    let s = readInput();
    console.log(s);
    if (s === '-999999') return;
    console.log(solution(s));
  }
}

main();

