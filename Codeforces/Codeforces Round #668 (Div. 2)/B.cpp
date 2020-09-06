#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <cstring>

using namespace std;

typedef long long ll;

int main(void) {
  // freopen("input.txt", "r", stdin);
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int t;
  cin >> t;
  while(t--) {
    int n;
    cin >> n;
    vector<ll> temp(n);
    for(int i=0;i<n;++i) {
      cin >> temp[i];
    }

    int mP = n-1;
    int pP = n-1;
    while(1) {
      if(mP < 0 || pP < 0) {
        break;
      }
      if(temp[mP] >= 0) {
        mP--;
      } else if(temp[pP] <= 0) {
        pP--;
      } else {
        if(mP < 0 || pP < 0) {
          break;
        }
        if(pP > mP) {
          pP--;
          continue;
        }
        if(abs(temp[mP]) > abs(temp[pP])) {
          temp[mP] += temp[pP];
          temp[pP] = 0;
          pP--;
        }
        else if(abs(temp[mP]) < abs(temp[pP])) {
          temp[pP] += temp[mP];
          temp[mP] = 0;
          mP--;
        } else {
          temp[pP] = temp[mP] = 0;
          mP++;
          pP++;
        }
      }
    }
    // cout << "middle" << endl;
    // for (int i = 0; i < n; ++i) {
    //   cout << temp[i] << ' ';
    // }
    // cout << endl;


    mP = pP = 0;
    ll ans = 0;
    while(1) {
      // cout << mP << ' ' << pP << endl;
      // cout << "middle" << endl;
      // for (int i = 0; i < n; ++i) {
      //   cout << temp[i] << ' ';
      // } 
      // cout << endl;
      if(mP >= n || pP >= n) {
        break;
      }
      if(temp[mP] >= 0) {
        mP++;
      } else if(temp[pP] <= 0) {
        pP++;
      } else {
        if(mP >= n || pP >= n) {
          break;
        }
        if(pP < mP) {
          pP++;
          continue;
        }
        if(abs(temp[mP]) > abs(temp[pP])) {
          temp[mP] += temp[pP];
          ans += abs(temp[pP]);
          temp[pP] = 0;
          pP++;
        }
        else if(abs(temp[mP]) < abs(temp[pP])) {
          temp[pP] += temp[mP];
          ans += abs(temp[mP]);
          temp[mP] = 0;
          mP++;
        } else {
          ans += abs(temp[mP]);
          temp[pP] = temp[mP] = 0;
          mP++;
          pP++;
        }
      }
    }
    //    cout << "middle" << endl;
    // for (int i = 0; i < n; ++i) {
    //   cout << temp[i] << ' ';
    // }
    // cout << endl;
    cout << ans << endl;
  }
  return 0;
}