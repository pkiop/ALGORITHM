#include <iostream>
#include <vector>

using namespace std;

const unsigned long long MOD = 1000000007;
unsigned long long pow(int n, int k) {
  unsigned long long res = 1;
  for (int i = 0; i < n; ++i) {
    res = (res % MOD) * (k % MOD);
  }
  return res;
}

int main(void) {
  int t;
  cin >> t;
  while (t--) {
    int n, k;
    cin >> n >> k;
    vector<bool> binaryOfK;
    while (k > 0) {
      binaryOfK.push_back(k % 2);
      k /= 2;
    }
    unsigned long long ans = 0;
    // for (int i = 0; i < binaryOfK.size(); ++i) {
    //   cout << binaryOfK[i] << ' ';
    // }
    for (int i = 0; i < binaryOfK.size(); ++i) {
      if (binaryOfK[i]) {
        ans += (pow(i, n) % MOD);
      }
    }
    cout << ans % MOD << endl;
  }
}