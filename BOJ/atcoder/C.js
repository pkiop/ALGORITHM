const readline = require("readline");
const rl = readline.createInterface({
  input: process.stdin,
  output: process.stdout
});

const solution = input => {
  let N = input;
    console.log((Math.pow(10, N) - Math.pow(8, N)) % (Math.pow(10, 9) - 7)); 
}

rl.on("line", function(line) {
  solution(line);
  rl.close();
}).on("close", function() {
  process.exit();
});