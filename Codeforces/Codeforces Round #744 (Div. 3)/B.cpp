#include <iostream>
#include <string>
#include <vector>
#include <cstring>
#include <algorithm>
using namespace std;

int arr[1001];
int copyArr[1001];

void printArr(int arr[], int n)
{
  for (int i = 0; i < n; ++i)
  {
    cout << arr[i] << ' ';
  }
  cout << endl;
}

void cyclingWithRange(int l, int r, int d)
{
  int rep = r - l + 1;
  int newArr[1001];
  for (int i = 0; i < rep; ++i)
  {
    newArr[(i - d + rep) % rep] = arr[l + i];
  }
  for (int i = 0; i < rep; ++i)
  {
    arr[l + i] = newArr[i];
  }
}

int main()
{
  // arr[0] = 1;
  // arr[1] = 3;
  // arr[2] = 2;
  // arr[3] = 4;

  // cyclingWithRange(1, 3, 2);
  // printArr(arr, 4);
  int N;
  cin >> N;
  for (int tc = 1; tc <= N; ++tc)
  {
    int n;
    cin >> n;
    memset(arr, 0, 1001);
    for (int i = 0; i < n; ++i)
    {
      cin >> arr[i];
      copyArr[i] = arr[i];
    }
    sort(copyArr, copyArr + n);
    // printArr(arr, n);
    // printArr(copyArr, n);
    vector<vector<int> > ans;
    for (int i = 0; i < n; ++i)
    {
      vector<int> temp;
      if (arr[i] != copyArr[i])
      {
        temp.push_back(i);
        temp.push_back(n - 1);
        int diff = 0;
        for (int j = i; j < n; ++j)
        {
          if (arr[j] == copyArr[i])
          {
            diff = (j - i);
            break;
          }
        }
        temp.push_back(diff);
        // cout << "shot : " << i << ' ' << n - 1 << ' ' << diff << endl;
        // cout << "before " << endl;
        // printArr(arr, n);
        cyclingWithRange(i, n - 1, diff);
        // cout << "after" << endl;
        // printArr(arr, n);
        if (diff == 0)
        {
          continue;
        }
        ans.push_back(temp);
      }
    }
    // cout << "printans " << endl;
    cout << ans.size() << endl;
    for (int i = 0; i < ans.size(); ++i)
    {
      for (int j = 0; j < ans[i].size(); ++j)
      {
        if (j != 2)
        {
          cout << ans[i][j] + 1 << ' ';
        }
        else
        {
          cout << ans[i][j];
        }
      }
      cout << '\n';
    }
  }
}