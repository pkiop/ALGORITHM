#include <iostream>
#include <algorithm>
#include <vector>
#include <cstring>

using namespace std;

bool chk[1001];
bool picked[1001];

bool cmp(int a, int b) {
  if(a > b) {
    return true;
  }
  return false;
}

bool cmp2(pair<int, int> a, pair<int, int> b) {
  if(a.first > b.first) {
    return true;
  }
  return false;
}

void makedivider(int num) {
  for(int i=1;i<=num/2;++i) {
    if(num % i == 0) {
      chk[i] = true;
      chk[num / i] = true;
    }
  }
}

int divcheck(int num) {
  int ret = 1;
  for(int i=1;i<=num/2;++i) {
    if(num % i == 0) {
      if(chk[num / i] == true)
        return num / i;
    }
  }
  return ret;
}

void maxDiv(int num) {
  cout << "maxdiv : " << num << endl;
  for(int i=1;i<=num;++i) {
    if(chk[i] == true) {
      cout << i << ' ';
    }
  }
  cout << endl;
}

int main(void) {
  freopen("input.txt", "r", stdin);
  int t;
  cin >> t;
  while(t--) {
    memset(chk, false, sizeof(chk));
    memset(picked, false, sizeof(picked));
    int n;
    cin >> n;
    vector<int> origin(n);
    vector<int> arr(n);
    vector<int> ans;
    vector<pair<int, int> > divhubo;
    for(int i=0;i<n;++i) {
      cin >> arr[i];
      origin[i] = arr[i];
    }
    sort(arr.begin(), arr.end(), cmp);
    makedivider(arr[0]);
    // for(int i=0;i<n;++i) {
    //   cout << arr[i] << ' ';
    // }
    // cout << endl;
    // maxDiv(arr[0]);
    for(int i=1;i<n;++i) {
      int ret = divcheck(arr[i]);
      if(ret > 1) {
        picked[arr[i]] = true;
        divhubo.push_back(make_pair(ret,arr[i]));
      }
    }
    sort(divhubo.begin(), divhubo.end(), cmp2);
    // cout << "divhubo test :: \n";
    // for(int i=0;i<divhubo.size(); ++i) {
    //   cout << divhubo[i].first << ' ' << divhubo[i].second << endl;
    // }
    // cout << "divhubo test :: end \n";
    // cout << "now : arr : " << arr[0];
    ans.push_back(arr[0]);
    bool noshake = false;
    int oidx = 0;
    if(arr[0] != origin[oidx++]) {
      noshake = true;
    }
    for(int i=0;i<divhubo.size();++i) {
      picked[divhubo[i].second] = true;
      ans.push_back(divhubo[i].second);
      if(divhubo[i].second != origin[oidx++]) {
        noshake = true;
      }
    } 
    // cout << "temp ans :: \n";
    // for(int i=0;i<ans.size();++i) {
    //   cout << ans[i] << ' ';
    // }    
    // cout << endl;
    for(int i=1;i<n;++i) {
      // cout << "check : " << arr[i] << ' ';
      if(picked[arr[i]] == false) {
        // cout << "ck success : " << arr[i] << endl;
        if(arr[i] != origin[oidx++]) {
          noshake = true;
        }
        ans.push_back(arr[i]);
      }
    }
    if(!noshake && n > 1) {
      int lv = ans[ans.size() - 1];
      for(int i=ans.size()-2;i>=0;--i) {
        if(lv != ans[i]) {
          // cout << "i : " << i << endl;
          // cout << lv << ' ' << ans[i] << endl;
          ans[ans.size() - 1] = ans[i];
          ans[i] = lv;
          // cout << lv << ' ' << ans[i] << endl;
          break;
        }
      }
    }
    // cout << "temp ans :: \n";
    for(int i=0;i<ans.size();++i) {
      cout << ans[i] << ' ';
    }    
    cout << endl;


  }
}