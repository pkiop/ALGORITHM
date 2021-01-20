// you can write to stdout for debugging purposes, e.g.

// console.log('this is a debug message');

function getBlocks(A, midValue) {
  let blocks = 1;
  let subSum = 0;
  A.forEach((el) => {
    if (subSum + el > midValue) {
      blocks += 1;
      subSum = el;
    } else {
      subSum += el;
    }
  })
  return blocks;
}

function solution(K, M, A) {
  // write your code in JavaScript (Node.js 8.9.4)
  let minValue = A.reduce((acc, el) => {
    return Math.max(acc, el);
  }, 0);

  let maxValue = A.reduce((acc, el) => {
    return acc + el;
  }, 0);

  while (minValue < maxValue) {
    let midValue = parseInt((minValue + maxValue) / 2, 10);
    let blocks = getBlocks(A, midValue);
    if (blocks > K) {
      minValue = midValue + 1;
    } else {
      maxValue = midValue;
    }
  }

  return minValue;
}