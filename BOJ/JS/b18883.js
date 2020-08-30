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

const solution = (input) => {
  const line = input.split(" ");
  let output = new Array();
  for(let i=0;i<Number(line[0]);++i) {
    let newArr = new Array();
    for(let j=1;j<=Number(line[1]);++j) {
      newArr.push(j+i*Number(line[1]));
    }
    output.push(newArr);
  }
  for(let i=0;i<Number(line[0]);++i) {
    console.log(...output[i]);
  }
}