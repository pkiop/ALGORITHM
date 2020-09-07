#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main(void) {
  string s;
  string type;
  cin >> type;
  while(1) {
    cin >> s;
    int i;
    string var = "";
    for(i=0;i<s.size()-1;++i) {
      if(('a' <= s[i] && s[i] <= 'z') || ('A' <= s[i] && s[i] <= 'Z')) {
        var += s[i];
      } else {
        break;
      }
    }
    cout << type;
    for(int j = s.size() - 2; j >= i; --j) {
      if(s[j] == '[') cout << ']';
      else if(s[j] == ']') cout << '[';
      else cout << s[j];
    }
    cout << ' ' << var << ';' << endl;
    if(s[s.size()-1] == ';') {
      break;
    }
  }
  return 0;
}

/*

int&&[] adcjwAB*[][], b, c*;

*/