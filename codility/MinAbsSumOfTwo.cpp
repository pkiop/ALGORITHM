// you can use includes, for example:
#include <algorithm>
#include <vector>

using namespace std;

// you can write to stdout for debugging purposes, e.g.
// cout << "this is a debug message" << endl;

int solution(vector<int> &A)
{
  sort(A.begin(), A.end());
  int firstIdx = 0;
  int lastIdx = A.size() - 1;

  int ans = 2100000000;
  while (firstIdx != lastIdx)
  {
    ans = min(ans, abs(A[firstIdx] + A[lastIdx]));
    if (abs(A[firstIdx]) > abs(A[lastIdx]))
    {
      firstIdx++;
    }
    else
    {
      lastIdx--;
    }
  }
  ans = min(ans, abs(A[firstIdx] * 2));
  return ans;
}
