#include <iostream>
#include <vector>

using namespace std;

int main(void) {
  long long n;
  cin >> n;
  vector<long long> arr;
  long long t;
  for(int i=0;i<n;++i) {
    cin >> t;
    arr.push_back(t);
  }

  if(n == 1) {
    cout << "1 1" << endl;
    cout << -arr[0] << endl;
    cout << "1 1" << endl;
    cout << "0" << endl;
    cout << "1 1" << endl;
    cout << "0" << endl;
  } else {
    cout << "1 " << n-1 << endl;
    for(int i=0;i<n-1;++i) {
      cout << arr[i] * (n-1) << ' ';
    }
    cout << endl;
    cout << n << ' ' << n << endl;
    cout << arr[n-1] * (n-1) << endl;
    cout << 1 << ' ' << n << endl;
    for(int i=0;i<n;++i) {
      cout << -arr[i] * n << endl;
    }
  }
}