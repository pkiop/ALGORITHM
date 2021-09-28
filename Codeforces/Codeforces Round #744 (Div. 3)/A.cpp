#include <iostream>
#include <string>
using namespace std;

int main()
{
  int N;
  cin >> N;
  for (int i = 0; i < N; ++i)
  {
    string input;
    cin >> input;
    int cnt[3];
    for (int j = 0; j < 3; ++j)
    {
      cnt[j] = 0;
    }
    for (int j = 0; j < input.size(); ++j)
    {
      cnt[input[j] - 'A']++;
    }
    if (cnt[1] == cnt[0] + cnt[2])
    {
      cout << "YES" << endl;
    }
    else
    {
      cout << "NO" << endl;
    }
  }
}