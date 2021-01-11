'use strict';

process.stdin.resume();
process.stdin.setEncoding('utf-8');

let inputString = '';
let currentLine = 0;

process.stdin.on('data', inputStdin => {
  inputString += inputStdin;
});

process.stdin.on('end', _ => {
  inputString = inputString.replace(/\s*$/, '')
    .split('\n')
    .map(str => str.replace(/\s*$/, ''));

  main();
});

function readLine() {
  return inputString[currentLine++];
}

// Complete the minimumBribes function below.
function minimumBribes(q) {
  let answer = 0;
  let arr = Array(100001);
  let arrCnt = Array(100001);
  for (let i = 0; i < arr.length; ++i) {
    arr[i] = i + 1;
  }
  for (let i = 0; i < q.length - 1; ++i) {
    let originValue = q[i];
    if (arr[i] !== originValue) {
      if (arr[i + 1] !== originValue) {
        if (arr[i + 2] !== originValue) {
          return 'Too chaotic';
        }
        let temp = arr[i + 2];
        arr[i + 2] = arr[i + 1];
        arr[i + 1] = temp;
        answer++;
      }
      let temp = arr[i + 1];
      arr[i + 1] = arr[i];
      arr[i] = temp;
      answer++;
    }
  }
  return answer;
}

function main() {
  const t = parseInt(readLine(), 10);

  for (let tItr = 0; tItr < t; tItr++) {
    const n = parseInt(readLine(), 10);

    const q = readLine().split(' ').map(qTemp => parseInt(qTemp, 10));

    console.log(minimumBribes(q));
  }
}
