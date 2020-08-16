const readline = require("readline");

const rl = readline.createInterface({
  input: process.stdin,
  output: process.stdout,
});

function *range(limit) {
  let i=-999;
  while(i < limit) {
    yield i++;
  }
}

const solution = (input) => {
  const a = Number(input[0]);
  const b = Number(input[1]);
  const c = Number(input[2]);
  const d = Number(input[3]);
  const e = Number(input[4]);
  const f = Number(input[5]);
  for(const x of range(1000)) {
    for(const y of range(1000)) {
      if(x * a + y * b == c && x * d + y * e == f) {
        console.log(x, y);
        return;
      }
    }
  }
};

rl.on("line", function (line) {
  solution(line.split(" "));
  rl.close();
}).on("close", function () {
  process.exit();
});
