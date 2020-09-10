#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int query(int idx1, int idx2) {
  cout << "? " << idx1 + 1 << ' ' << idx2 + 1 << endl;
  int temp;
  cin >> temp;
  return temp;
}

int main(void) {
  int n;
  cin >> n;
  vector<int> arr(n);

  int val = 0;
  for(int i=1;i<n;++i) {
    int q1 = query(val, i);
    int q2 = query(i, val);
    if(q1 > q2) {
      arr[val] = q1;
      val = i;
    } else {
      arr[i] = q2;
    }
  }
  arr[val] = n;
  cout << "! ";
  for(int i=0;i<n;++i) {
    cout << arr[i] << ' ';
  }
  return 0;
}