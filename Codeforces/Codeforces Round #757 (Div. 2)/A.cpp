#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

int main() {
  int t;
  cin >> t;
  while (t--) {
    int n, l, r, k;
    cin >> n >> l >> r >> k;
    vector<int> arr(n);
    for (int i = 0; i < n; ++i) {
      cin >> arr[i];
    }
    sort(arr.begin(), arr.end());

    unsigned long long sum = 0;
    int ans = 0;
    for (int i = 0; i < n; ++i) {
      if (arr[i] > r) break;
      if (sum + arr[i] > k) break;
      if (arr[i] >= l) {
        sum += arr[i];
        ans++;
      }
    }
    cout << ans << endl;
  }
}