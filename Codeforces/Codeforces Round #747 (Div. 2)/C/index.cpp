#include <cmath>
#include <cstring>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

vector<int> primeList;
const int NUM = 300007;
int coreList[NUM];
int tempCoreList[NUM];
void setPrime() {
  for (int i = 2; i <= NUM; i++) {
    coreList[i] = i;
  }

  for (int i = 2; i <= sqrt(NUM); i++) {
    if (coreList[i] == 0) continue;

    for (int j = 2 * i; j <= NUM; j += i) {
      coreList[j] = 0;
    }
  }

  for (int i = 2; i <= NUM; i++) {
    if (coreList[i] != 0) primeList.push_back(i);
  }
}

int main(void) {
  setPrime();

  int t;
  cin >> t;
  while (t--) {
    memset(coreList, 0, NUM);
    int n;
    char c;
    string s;
    cin >> n >> c >> s;

    vector<bool> pick;
    bool onePick = false;
    for (int i = 0; i < n; ++i) {
      bool v = s[i] != c;
      if (v) {
        onePick = true;
      }
      pick.push_back(v);
    }
    if (!onePick) {
      cout << '0' << endl;
      continue;
    }
    if (!pick[n - 1]) {
      cout << "1\n" << n << endl;
      continue;
    }

    bool findAns = false;
    int calN = n;
    int maxCorePrime;
    for (int i = 0; primeList.size() > i && primeList[i] < n; ++i) {
      while (calN % primeList[i] == 0) {
        coreList[primeList[i]]++;
        calN /= primeList[i];
      }
    }

    for (int i = n - 1; i >= 2; --i) {
      if (pick[i]) continue;
      memset(tempCoreList, 0, NUM);
      int calN = n;
      for (int j = 0; primeList[j] < n; ++j) {
        while (calN % primeList[j] == 0) {
          tempCoreList[primeList[j]]++;
          calN /= primeList[j];
        }
      }

      for (int coreIdx = 0; primeList.size() > i && primeList[coreIdx] < n;
           ++coreIdx) {
        int nowPrime = primeList[coreIdx];
        if (coreList[nowPrime] < tempCoreList[nowPrime]) {
          findAns = true;
          cout << "1\n" << i << endl;
          break;
        }
      }

      if (findAns) break;
    }
    if (findAns) continue;
    cout << "2\n" << n - 1 << ' ' << n << endl;
  }
}