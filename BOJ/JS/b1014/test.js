const array2D = [];
for (let i = 0; i < 10; ++i) {
  const arr = new Array(10).fill(-1);
  array2D.push(arr);
}

console.log('array2D : ', array2D);
array2D[0][0] = 1;
console.log('array2D : ', array2D);
console.log(array2D[0] === array2D[1]);
