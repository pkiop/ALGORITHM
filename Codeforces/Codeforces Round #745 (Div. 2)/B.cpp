#include <iostream>

using namespace std;

int main() {
  int tc;
  cin >> tc;
  for(int i=0;i<tc;++i) {
    int n; 
    cin >> n;
    long long ans = 1;
    if(n == 1) {
      cout << 1 << endl;
      continue;
    }
    if(n == 2) {
      cout << 12 << endl;
      continue;
    }
    for(long long j=2*n; j>=3; --j) {
      ans = (j * (ans % 1000000007)) % 1000000007;
    }
    cout << ans << endl;
  }
}