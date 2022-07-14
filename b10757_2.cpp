#include <iostream>
using namespace std;

int arr1[100001];
int arr2[100001];
int arr[100001];
int len;

int main() {
  string a, b;
  cin >> a >> b;

  for (int i = a.length() - 1; i >= 0; i--) {
    arr1[a.length() - 1 - i] = a[i] - '0';
  }

  for (int i = b.length() - 1; i >= 0; i--) {
    arr2[b.length() - 1 - i] = b[i] - '0';
  }

  if (a.length() > b.length()) {
    len = a.length();
  } else {
    len = b.length();
  }

  for (int i = 0; i < len; i++) {
    arr[i] = arr1[i] + arr2[i] + arr[i];
    if (arr[i] >= 10) {
      arr[i + 1]++;
      arr[i] -= 10;
    }
  }
  if (arr[len] != '0') {
    cout << arr[len];
  }

  for (int i = len - 1; i >= 0; i--) {
    cout << arr[i];
  }

  return 0;
}
