
//   * top-down은 다음에 해보자. 오랜만의 botton-up
//   * 
// 맨처음 case는 1,1,1 
//   * 
// 다음부터 cache[N][L][R]은 이전 정보를 받아온 다음 마지막 길이 1번건물을 어디에 놓냐만 생각하면 된다. 
//   * 
// cache[N - 1][L - 1][R] 이 식은 오른쪽에 1을 놓았다고 생각해서 이전정보에서 더해주는 것
//   * 
// cache[N - 1][L][R - 1] 이식은 반대로 왼쪽에 1을 놓았다고 생각한 것
//   * 
// cache[N - 1][L][R] * (N - 2) 이것은 양 끝을 제외하고 1을 놓았다고 생각한 것. 그래서 L과 R에 변화가 없다. 


#include <iostream>
using namespace std;
long long cache[101][101][101];
int main(void)
{
        int n, l, r;
        cin >> n >> l >> r;
        cache[1][1][1] = 1;
        for (int N = 2; N <= n; ++N) {
               for (int L = 1; L <= l; ++L) {
                       for (int R = 1; R <= r; ++R) {
                               cache[N][L][R] = cache[N - 1][L - 1][R] + cache[N - 1][L][R - 1] + cache[N - 1][L][R] * (N - 2);
                               cache[N][L][R] %= 1000000007;
                       }
               }
        }
        cout << cache[n][l][r] << endl;
        return 0;
}