#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int arr[1000010];
int cmp;
int bs(int left, int right) {
  int mid = (left + right) / 2;
  if(left > right) {
    return 0;
  }
  int tval = arr[mid];
  if(tval > cmp) {
    return bs(left, mid-1);
  } else if(tval < cmp) {
    return bs(mid+1, right);
  } else {
    return 1;
  }
}

int main(void) {
  int t;
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  cin >> t;
  while(t--) {
    int a, b;
    cin >> a;
    for(int i=0;i<a;++i) {
      cin >> arr[i];
    }
    sort(arr,arr+a);
    cin >> b;
    for(int i=0;i<b;++i) {
      cin >> cmp;
      cout << bs(0,a-1) << '\n';
    }
  }
}