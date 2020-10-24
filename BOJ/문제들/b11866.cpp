#include <iostream>
#include <queue>

using namespace std;

int main(void) {
  int n, k;
  cin >> n >> k;
  queue<int> q;
  for(int i=1;i<=n;++i) {
    q.push(i);
  }  
  int cnt = k-1;
  cout << '<';
  while(!q.empty()) {
    if(!cnt) {
      cout << q.front();
      if(q.size() != 1) {
        cout << ", ";
      }
      cnt = k-1;
      q.pop();
    } else {
      q.push(q.front());
      q.pop();
      cnt--;
    }
  }
  cout << '>';
  return 0;
}