#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

typedef long long ll;
const long long LIMIT = 20000000000;
ll cal(ll ,ll);
int main(void) {
  int n;
  cin >> n;
  vector<ll> arr;
  ll answer = 0;
  ll t;
  for(int i=0;i<n;++i) {
    cin >> t;
    arr.push_back(t);
    answer += t - 1;
  }
  ll c = 2;
  ll pow = 2;
  ll temp;
  sort(arr.begin(), arr.end());
  while(true) {
    temp = 0;
    for(int i=0;i<n;++i) {
      ll ret = cal(c, i);
      if(ret > LIMIT) {
        cout << answer << endl;
        return 0;
      }
      temp += abs(arr[i] - cal(c, i));
    } 
    if(answer > temp) {
      answer = temp;
    }
    c += 1;
  }
}

ll cal(ll c, ll rep) {
  ll ret = 1;
  for(int i=0;i<rep;++i) {
    ret = ret * c;
  }
  return ret;
}