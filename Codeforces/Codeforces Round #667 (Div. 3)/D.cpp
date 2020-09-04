#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;
int arr[20];
int jari = 0;
void clearArr() {
  for(int i=0;i<20;++i) {
    arr[i] = 0;
  }
  jari = 0;
}

void debugArr() {
  for(int i=0;i<20;++i) {
    cout << arr[i] << ' ';
  }
  cout << endl;
}

int nowDigitSum = 0;
void findDigitSum() {
  nowDigitSum = 0;
  for(int i=0;i<20;++i) {
    nowDigitSum += arr[i];
  }
}

unsigned long long numberUpdate() {
  unsigned long long ret = 10 - arr[jari];
  for(int i=jari; i<19;++i) {
    arr[i] = 0;
    arr[i+1] += 1;
    if(arr[i+1] != 10) {
      jari++;
      return ret;
    }
  }
  return 99999999;
}

unsigned long long tenpow(int rep) {
  unsigned long long ret = 1;
  for(int i=0;i<rep;++i) {
    ret *= 10;
  }
  return ret;
}

int main(void) {
  // freopen("input.txt", "r", stdin);
  int t;
  cin >> t;
  while(t--) {
    clearArr(); 
    string n;
    int s;
    cin >> n >> s;
    int ii = 0;
    for(int i=n.size()-1;i>=0;--i) {
      arr[ii++] = n[i] - '0';
    }

    unsigned long long ans = 0;
    while(1) {
      findDigitSum();
      if(nowDigitSum <= s) {
        cout << ans << endl;
        break;
      }
      ans += tenpow(jari) * numberUpdate();
    }
  }
}