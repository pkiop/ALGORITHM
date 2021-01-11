
const gcd = (n, d) => {
  if (d == 0) {
    return n;
  }
  return gcd(n, n % d);
}

const rotate = (arr, d, n) => {
  for (let i = 0; i < gcd(d, n); i += 1) {
    let t = arr[i];
    let j = i
    for (; j < n; j += d) {
      arr[j] = arr[j + d];
    }
    arr[j - d] = t;
  }
}

let testarr = [1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12];
rotate(testarr, 3, testarr.length);
console.log(testarr);