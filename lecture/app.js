const fs = require('fs');
const readline = require('readline');

const rl = readline.createInterface({
  // input: process.stdin,
  input: fs.createReadStream('./input.txt'),
  output: process.stdout,
});

const input = [];
rl.on('line', function (line) {
  const split = line.split(' ');
  input.push([Number(split[0]), Number(split[1])]);
}).on('close', function () {
  solve(input);
  process.exit();
});

function solve(input) {
  
}
