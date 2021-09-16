let fs = require('fs');
let input = fs.readFileSync('/dev/stdin').toString().split('\n');
// let input = fs.readFileSync('./input.txt').toString().split('\n');

let readlineIdx = 0;
const readInput = () => input[readlineIdx++];

function main() {
  let [a] = readInput().split(' ');
  a = Number(a);
  Array(9).fill(0).forEach((el, index) => {
    console.log(`${a} * ${index + 1} = ${a * (index + 1)}`);
  })
}

main();

