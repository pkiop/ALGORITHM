#include <iostream>
#include <string>
#include <deque>
#include <cstring>
#include <algorithm>
using namespace std;

int arr[200001];
int main()
{
  int N;
  cin >> N;
  for (int tc = 0; tc < N; ++tc)
  {
    int n;
    cin >> n;
    for (int i = 0; i < n; ++i)
    {
      cin >> arr[i];
    }
    deque<int> dq;
    dq.push_back(arr[0]);
    for (int i = 1; i < n; ++i)
    {
      if (arr[i] >= dq[0])
      {
        dq.push_back(arr[i]);
      }
      else
      {
        dq.push_front(arr[i]);
      }
    }
    for (int i = 0; i < n; ++i)
    {
      cout << dq[i] << ' ';
    }
    cout << endl;
  }
}