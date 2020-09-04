#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

int main(void) {
  // freopen("input.txt", "r", stdin);
  int t;
  cin >> t;
  int a, b;
  while(t--) {
    cin >> a >> b;
    int temp = abs(a - b) / 10;
    if(abs(a - b) % 10 != 0) {
      temp++;
    } 
    cout << temp << '\n';
  }
}