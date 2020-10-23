#include <iostream>
#include <string>

using namespace std;

int main(void) {
  string s = "temp";
  while(true) {
    cin >> s;
    if(s == "0") {
      return 0;
    }

    bool yes = true;
    for(int i=0;i<s.size() / 2;++i) {
      if(s[i] != s[s.size() - i - 1]) {
        yes = false;
        break;
      }
    }
    cout << (yes ? "yes" : "no") << endl;
  }
}