// const input = require('fs').readFileSync('/dev/stdin').toString().split('\n');
const input = require('fs').readFileSync('./input.txt').toString().split('\n');
const [inputN, inputK] = input[0].split(' ').map((e) => +e);
let dataListInput = [1];
for (let i = 1; i < input.length; ++i) {
  dataListInput.push(input[i].split(' ').map((e) => +e));
}
if (dataListInput[dataListInput.length - 1].length !== 2) dataListInput.pop();

let DP = new Array(102);

function solution(n, k, dataList) {
  for (let i = 0; i <= k; ++i) {
    DP[i] = new Array(k + 1).fill(0);
  }
  for (let i = 1; i <= n; ++i) {
    for (let j = 1; j <= k; ++j) {
      if (j < dataList[i][0]) DP[i][j] = DP[i - 1][j];
      else
        DP[i][j] = Math.max(
          DP[i - 1][j],
          DP[i - 1][j - dataList[i][0]] + dataList[i][1]
        );
    }
  }

  console.log('dp : ', DP);
  console.log(DP[dataList.length - 1][k]);
}

solution(inputN, inputK, dataListInput);
