#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

bool sorting(pair<int, int> v, pair<int, int> v2) { return v.first > v2.first; }

bool indexSorting(pair<int, int> v, pair<int, int> v2) {
  return v.second < v2.second;
}
typedef long long ll;

int main() {
  int t;
  cin >> t;
  while (t--) {
    int n;
    cin >> n;
    vector<pair<long long, long long> > arr;
    int test;
    for (int i = 0; i < n; ++i) {
      cin >> test;
      arr.push_back(make_pair(test, i + 1));
    }
    sort(arr.begin(), arr.end(), sorting);
    unsigned long long ans = 0;
    ll y = 1;
    vector<pair<ll, ll> > ansVec;
    ansVec.push_back(make_pair(0, 0));
    for (int i = 0; i < n; ++i) {
      ans += 2 * (y * arr[i].first);
      if (i % 2 == 1) {
        ansVec.push_back(make_pair(-y, arr[i].second));
        y++;
      } else {
        ansVec.push_back(make_pair(y, arr[i].second));
      }
    }
    sort(ansVec.begin(), ansVec.end(), indexSorting);
    cout << ans << endl;
    for (int i = 0; i < ansVec.size(); ++i) {
      cout << ansVec[i].first << ' ';
    }
    cout << endl;
  }
}