let fs = require('fs');
// let input = fs.readFileSync('/dev/stdin').toString().split('\n');
let input = fs.readFileSync('./input.txt').toString().split('\n');

let readlineIdx = 0;

const readInput = () => input[readlineIdx++];

class Trie {
  constructor() {
    this.pass = false;
    this.end = false;
    this.child = {};
  }

  insert(trie, arr) {
    let el = parseInt(arr[0], 10);
    const nowChild = trie.child[el];
    if (nowChild === undefined) {
      const nT = new Trie();
      nT.pass = true;
      trie.child[el] = nT;
      if (arr.length === 1) {
        nT.end = true;
        return true;
      }
      return this.insert(nT, arr.slice(1));

    }
    if (nowChild.end === true) {
      return false;
    }
    if (arr.length === 1) {
      if (nowChild.pass) {
        return false;
      }
      nowChild.pass = true;
      nowChild.end = true;
      return true;
    }
    nowChild.pass = true;
    return this.insert(nowChild, arr.slice(1));
  }
}

function solution(temparr, n) {
  const trie = new Trie();
  for (let i = 0; i < n; ++i) {
    const nowArr = temparr[i].split("").filter((el) => el !== ' ');
    if (trie.insert(trie, nowArr) === false) {
      return false;
    }
  }
  return true;
}

function main() {
  let t = readInput();
  while (t--) {
    let n = readInput();
    let temparr = new Array();
    for (let i = 0; i < n; ++i) {
      temparr.push(readInput());
    }
    console.log(solution(temparr, n) === true ? 'YES' : 'NO');
  }
}

main();

