function solution(A) {
  let minAvg = (A[0] + A[1]) / 2;
  let minIdx = 0;
  for (let i = 2; i < A.length; ++i) {
    let avg = (A[i - 2] + A[i - 1] + A[i]) / 3;
    if (minAvg > avg) {
      minAvg = avg;
      minIdx = i - 2;
    }
    avg = (A[i - 1] + A[i]) / 2;
    if (minAvg > avg) {
      minAvg = avg;
      minIdx = i - 1;
    }
  }
  return minIdx;
}