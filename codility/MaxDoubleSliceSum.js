function solution(A) {
  let increaseArray = new Array(A.length).fill(0);
  let decreaseArray = new Array(A.length).fill(0);

  for (let i = 1; i < A.length - 1; ++i) {
    increaseArray[i] = Math.max(increaseArray[i - 1] + A[i], 0);
  }
  for (let i = A.length - 2; i > 0; --i) {
    decreaseArray[i] = Math.max(decreaseArray[i + 1] + A[i], 0);
  }
  let ans = -9999999;

  for (let i = 1; i < A.length - 1; ++i) {
    ans = Math.max(increaseArray[i - 1] + decreaseArray[i + 1], ans);
  }
  return ans;
}