#include <iostream>
#include <string>
#include <vector>
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

    vector<vector<int> > answer;

    int l = 0, r = 1;
    bool finish = false;
    while (true)
    {
      if (l == r)
      {
        r++;
        if (r == n)
        {
          finish = true;
        }
      }
      if (finish)
      {
        break;
      }
      while (arr[r] == 0)
      {
        r++;
        if (r == n)
        {
          finish = true;
          break;
        }
      }
      if (finish)
      {
        break;
      }
      while (arr[l] == 0)
      {
        l++;
      }
      if (l == r)
      {
        continue;
      }
      while (arr[l] > 0 && arr[r] > 0)
      {
        vector<int> temp;
        temp.push_back(l + 1);
        temp.push_back(r + 1);
        answer.push_back(temp);
        arr[l]--;
        arr[r]--;
      }
    }

    cout << answer.size() << endl;
    for (int i = 0; i < answer.size(); ++i)
    {
      cout << answer[i][0] << ' ' << answer[i][1] << '\n';
    }
  }
}