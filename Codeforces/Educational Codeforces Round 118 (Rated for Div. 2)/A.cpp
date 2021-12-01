#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main() {
  int t;
  cin >> t;
  while (t--) {
    string a, c;
    int b, d;
    cin >> a >> b >> c >> d;
    if (a.length() + b > c.length() + d) {
      cout << '>' << endl;
      continue;
    }
    if (a.length() + b < c.length() + d) {
      cout << '<' << endl;
      continue;
    }
    int i = 0;
    for (i = 0; i < min(a.length(), c.length()); ++i) {
      if (a[i] > c[i]) {
        cout << '>' << endl;
        break;
      }
      if (a[i] < c[i]) {
        cout << '<' << endl;
        break;
      }
    }
    if (i == min(a.length(), c.length())) {
      bool finish = false;
      if (a.length() > c.length()) {
        for (int ii = i; ii < a.length(); ++ii) {
          if (a[ii] != '0') {
            cout << '>' << endl;
            finish = true;
            break;
          }
        }
        if (finish) continue;
        cout << '=' << endl;
      }
      if (a.length() < c.length()) {
        for (int ii = i; ii < c.length(); ++ii) {
          if (c[ii] != '0') {
            cout << '<' << endl;
            finish = true;
            break;
          }
        }
        if (finish) continue;
        cout << '=' << endl;
      }
      if (a.length() == c.length()) {
        cout << '=' << endl;
      }
    }
  }
}