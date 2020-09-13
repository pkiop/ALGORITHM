const readline = require("readline");
const rl = readline.createInterface({
  input: process.stdin,
  output: process.stdout
});

const solution = input => {
  [a,b,c,d] = input;
  let ans = a * c;
  ans = Math.max(ans, a * d);
  ans = Math.max(ans, b * c);
  ans = Math.max(ans, b * d);
  console.log(ans);
  
}

rl.on("line", function(line) {
  let input = line.split(' ');
  solution(input);
  rl.close();
}).on("close", function() {
  process.exit();
});