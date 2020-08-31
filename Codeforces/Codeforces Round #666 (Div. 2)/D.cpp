#include <iostream>
#include <algorithm>

using namespace std;

int main(void) {
  int t;
  cin >> t;
  while(t--) {
    int n;
    cin >> n;
    int maxv = 0;
    int total = 0;
    int temp;
    while(n--) {
      cin >> temp;
      maxv = max(maxv, temp);
      total += temp; 
    }

    if(maxv * 2 > total) {
      cout << "T" << endl;
    } else if (total % 2 == 0) {
      cout << "HL" << endl;
    } else {
      cout << "T" << endl;
    }
  }
  return 0;
}