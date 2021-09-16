const fs = require('fs');
const filePath = process.platform === 'linux' ? '/dev/stdin' : './input.txt';
let input = fs.readFileSync(filePath).toString().split('\n');
const C = +input[0];
const inputs = [];
let nowI = 1;

let cnt = 0;
let maxCnt = 0;
let visited = Array(10).fill(Array(10).fill(-1));
for (let i = 1; i <= C; ++i) {
  const [N, M] = input[nowI].split(' ').map((el) => +el);
  const table = [];
  for (let j = 1; j <= N; ++j) {
    const tempTable = [];
    for (let k = 0; k < M; ++k) {
      tempTable.push(input[nowI + j][k]);
    }
    table.push(tempTable);
  }
  nowI += N + 1;
  inputs.push({ N, M, table });
}

const isPointInTable = (N, M, table) => (x, y, except) => {
  if (x < 0 || x >= M || y < 0 || y >= N) {
    return false;
  }
  if (except.includes(table[y][x])) {
    return false;
  }
  return true;
};

function isOkToPut(N, M, x, y, table) {
  const isPIT = isPointInTable(N, M, table);
  if (!isPIT(x, y, ['x', 'p'])) {
    return false;
  }
  if (x - 1 >= 0 && !isPIT(x - 1, y, ['p'])) {
    return false;
  }
  if (x + 1 < M && !isPIT(x + 1, y, ['p'])) {
    return false;
  }
  if (x - 1 >= 0 && y - 1 >= 0 && !isPIT(x - 1, y - 1, ['p'])) {
    return false;
  }
  if (x + 1 < M && y - 1 >= 0 && !isPIT(x + 1, y - 1, ['p'])) {
    return false;
  }
  if (y - 1 >= 0 && !isPIT(x, y - 1, [])) {
    return false;
  }
  return true;
}

function dfs(N, M, x, y, table) {
  for (let i = 0; i < N; ++i) {
    for (let j = 0; j < M; ++j) {
      // printTable(table, N, M);
      if (isOkToPut(N, M, j, i, table)) {
        if (visited[j][i] > cnt) {
          continue;
        }
        cnt++;
        visited[j][i] = cnt;
        maxCnt = Math.max(cnt, maxCnt);
        table[i][j] = 'p';
        dfs(N, M, j, i, table);
        table[i][j] = '.';
        cnt--;
      }
    }
  }
}

function printTable(table, N, M) {
  for (let i = 0; i < N; ++i) {
    console.log(table[i]);
  }
}

function solution(C, inputs) {
  // Write your code
  for (let test = 0; test < C; ++test) {
    cnt = 0;
    maxCnt = 0;
    const { N, M, table } = inputs[test];
    for (let i = 0; i < 10; ++i) {
      for (let j = 0; j < 10; ++j) {
        visited[i][j] = -1;
      }
    }
    dfs(N, M, 0, 0, table);
    console.log(maxCnt);
  }
}

solution(C, inputs);
