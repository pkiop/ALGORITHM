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
  // freopen("input.txt", "r", stdin);
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
    if(n == 1) {
      cin >> n;
      cout << n << endl;
      continue;
    }
    for(int i=0;i<n;++i) {
      cin >> arr[i];
      origin[i] = arr[i];
    }
    sort(arr.begin(), arr.end(), cmp);
    ans.push_back(arr[0]);

    int nowVal = arr[0];
    arr[0] = -1;
    while(1) {
      int tempVal = 0;
      int pickIdx = 0;
      // for(int i=0;i<n;++i) {
      //   cout << arr[i] << ' ';
      // }
      // cout << endl;
      memset(chk, false, sizeof(chk));
      makedivider(nowVal);
      for(int j=0;j<n;++j){
        if(arr[j] == -1) {
          continue;
        }
        int ret = divcheck(arr[j]);
        if(tempVal <= ret) {
          pickIdx = j;
          tempVal = ret;
        }
      }
      nowVal = tempVal;
      ans.push_back(arr[pickIdx]);
      if(ans.size() == n) break;
      arr[pickIdx] = -1;
    }
 
    for(int i=0;i<ans.size();++i) {
      cout << ans[i] << ' ';
    }    
    cout << endl;


  }
}