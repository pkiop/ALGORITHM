#include <iostream>
using namespace std;

int main(void) {
  int n;
  cin >> n;
  int a,b,c;
  for(int i=0;i<n;++i) {
    cin >> a >> b >> c;
    // cout << a << b << c << endl;
    int col = c / a;
    int row = c - a * col;
    if(row == 0) {
      col-=1;
      row = a;
    }
    cout << row;
    if(col+1 < 10) {
      cout << '0';
    }
    cout << col+1 << endl;
  }
}