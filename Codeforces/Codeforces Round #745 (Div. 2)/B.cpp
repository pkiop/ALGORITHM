#include <iostream>

using namespace std;

int main()
{
  int tc;
  cin >> tc;
  for (int i = 0; i < tc; ++i)
  {
    long long n, m, k;
    cin >> n >> m >> k;

    if (m < n - 1 || m > (n * (n - 1) / 2))
    {
      cout << "NO" << endl;
    }
    else if (n == 1)
    {
      if (k > 1)
      {
        cout << "YES" << endl;
      }
      else
      {
        cout << "NO" << endl;
      }
    }
    else if (m < (n * (n - 1) / 2))
    {
      if (k > 3)
      {
        cout << "YES" << endl;
      }
      else
      {
        cout << "NO" << endl;
      }
    }
    else if (k > 2)
    {
      cout << "YES" << endl;
    }
    else
    {
      cout << "NO" << endl;
    }
  }
}