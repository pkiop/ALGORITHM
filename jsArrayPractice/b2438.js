let fs = require('fs');
// let input = fs.readFileSync('/dev/stdin').toString().split('\n');
let input = fs.readFileSync('./input.txt').toString().split('\n');

let readlineIdx = 0;
const readInput = () => input[readlineIdx++];

function main() {
  let [a, b] = readInput().split(' ');
}

main();
