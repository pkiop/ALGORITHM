#include <iostream>

using namespace std;

int main(void) {
  int t;
  cin >> t;
  while(t--) {
    int n;
    cin >> n;
    int zerocnt = 0;
    int temp;
    for(int i=0;i<n;++i) {
      cin >> temp;
      if(temp == 0) {
        zerocnt++;
      }
    }
    if(zerocnt >= n / 2) {
      cout << n / 2 << endl;
      for(int i=0;i<n / 2;++i) {
        cout << 0 << ' ';
      } 
    } else {
      if(n == 2) {
        cout << n << endl;
        cout << 1 << ' ' << 1 << endl;
      } else {
        if((n / 2) % 2 == 1) {
          cout << n / 2 + 1 << endl;
          for(int i=0;i<n/2+1;++i) {
            cout << 1 << ' ';
          }
        } else {
        cout << n / 2 << endl;
          for(int i=0;i<n/2;++i) {
            cout << 1 << ' ';
          }
          }
      }
    }
    cout << endl;
  }
}