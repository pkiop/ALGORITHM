const readline = require("readline");
const rl = readline.createInterface({
  input: process.stdin,
  output: process.stdout
});

rl.on("line", function(line) {
  solution(line);
  rl.close();
}).on("close", function() {
  process.exit();
})

const solution = line => {
  [d1, d2, d3] = line.split(' ');
  d1 = Number(d1);
  d2 = Number(d2);
  d3 = Number(d3);
  a = ((d1 + d2 - d3) / 2).toFixed(1);
  b = ((d1 - d2 + d3) / 2).toFixed(1);
  c = ((d2 + d3 - d1) / 2).toFixed(1);
  if(a <= 0 || b <= 0 || c <= 0) {
    console.log(-1);
    return;
  }
  console.log(1);
  console.log(a,b,c);
}
