#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

int arr1[200011];
int arr2[200011];

void debug() {
  for(int i=0;i<20;++i) {
    cout << arr1[i] << ' '; 
  }
  cout << endl;
  for(int i=0;i<20;++i) {
    cout << arr2[i] << ' '; 
  }
  cout << endl;
}

void clearArr() {
  for(int i=0;i<200001;++i) {
    arr1[i] = arr2[i] = 0;
  }
}

int main(void) {
  freopen("input.txt", "r", stdin);
  int t;
  cin >> t;
  while(t--) {
    clearArr();
    int n, k;
    cin >> n >> k;
    k++;
    int temp;
    for(int i=0;i<n;++i) {
      cin >> temp;
      arr1[temp]++;
    }
    for(int i=0;i<n;++i) {
      cin >> temp;
    }
    for(int i=1;i<200001;++i) {
      arr2[i] += arr1[i] + arr2[i-1];
    }
    int ans = 0;
    int max1 = 0;
    int maxIdx1 = 0;
    cout << "t1" << endl;
    for(int i=k;i<200001;++i) {
      if(max1 < arr2[i] - arr2[i-k]) {
        max1 = arr2[i] - arr2[i-k];
        maxIdx1 = i;
      }
      max1 = max(max1, arr2[i] - arr2[i-k]);
    }
    // debug();
    // cout << max1 << endl;
    // cout << maxIdx1 << endl;
    ans += max1;
    max1 = 0;
    int maxIdx = 0;
    cout << "t1" << endl;
    for(int i=k;i<200001;++i) {
      if(maxIdx1 - k <= i && i <= maxIdx1) continue;
      if(max1 < arr2[i] - arr2[i-k]) {
        max1 = arr2[i] - arr2[i-k];
        maxIdx = i;
      }
      max1 = max(max1, arr2[i] - arr2[i-k]);
    }
    // cout << max1 << endl;
    // cout << maxIdx << endl;
    ans += max1;
    cout << ans << '\n';
  }
}