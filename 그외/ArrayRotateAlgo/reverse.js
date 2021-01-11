
function rotate(arr, n, d) {
  const frontArr = arr.slice(0, d).reverse();
  const backArr = arr.slice(d, n).reverse();
  const res = frontArr.concat(backArr);
  return res.reverse();
}

const arr = [1, 2, 3, 4, 5, 6, 7];
console.log(rotate(arr, arr.length, 2));