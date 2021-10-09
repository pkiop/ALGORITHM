#include <iostream>

using namespace std;

int main(void) {
  int t;
  cin >> t;
  while (t--) {
    unsigned long long n;
    cin >> n;
    if (n == 1) {
      cout << 0 << ' ' << 1 << endl;
      continue;
    }
    cout << '-' << (n - 1) << ' ' << (n) << endl;
  }
}