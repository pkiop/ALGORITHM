#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int cnt[500001];

int rounding(int sum, int n) {
  int ret = (abs(sum) * 10) / n;
  // cout << "ret : " << ret << endl;
  // cout << "ret % 10 : " << ret%10 << endl;
  // cout << "ret / 10 : " << ret/10 << endl;
  if(sum >= 0 && ret % 10 >= 5) {
    ret = ret / 10 + 1;
  } 
  else if(sum >= 0 && ret % 10 < 5) {
    ret = ret / 10;
  } 
  else if(sum < 0 && ret % 10 >= 5) {
    ret = ret / 10 + 1;
  } 
  else if(sum < 0 && ret % 10 < 5) {
    ret = ret / 10;
  } else {
    ret = ret / 10;
  }
  // cout << "ret : " << ret << endl;
  return (sum >= 0 ? ret : ret * -1);
}

int goodValue() {
  int nowMax = 1;
  vector<int> hubo;
  for(int i=0;i<500001;++i) {
    if(cnt[i] > nowMax) {
      nowMax = cnt[i];
      hubo.clear();
      hubo.push_back(i - 5000);
    } else if (cnt[i] == nowMax) {
      hubo.push_back(i - 5000);
    }
  }
  sort(hubo.begin(), hubo.end());
  if(hubo.size() == 1) {
    return hubo[0];
  } else {
    return hubo[1];
  }
}

void roundingTest() {
  cout << "RT" << endl;
  cout << rounding(-1214,7) << " " << (12140 / 7) << endl;
  cout << rounding(-1215,7) << " " << (12150 / 7) << endl;
  cout << rounding(-1216,7) << " " << (12160 / 7) << endl;
  cout << rounding(-1217,7) << " " << (12170 / 7) << endl;
  cout << "RT" << endl;
}

int main(void) {
  // roundingTest();
  int n;
  cin >> n;
  vector<int> arr(n);
  int one = 0;
  for(int i=0;i<n;++i) {
    cin >> arr[i];
    cnt[arr[i] + 5000]++;
    one += arr[i];
  }

  sort(arr.begin(), arr.end());
  // cout << rounding(one, n) << endl; 
  printf("%.0f\n", (double)one / n);
  cout << arr[n / 2] << endl;
  cout << goodValue() << endl;
  cout << arr[arr.size() - 1] - arr[0] << endl;
  return 0;
}