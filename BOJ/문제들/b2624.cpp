

#include <iostream>
#include <vector>
#include <cstring>
using namespace std;
vector<pair<int, int>> coin;
int cache[10001][101];
int n;
int money;
int go(int cash, int idx) {
        if (cash == 0) {
               return 1;
        }
        if (idx >= n) {
               return 0;
        }
        int& ret = cache[cash][idx];
        if (ret != -1) {
               return ret;
        }
        ret = 0;
        for (int i = 0; i <= coin[idx].second; ++i) {
               if (cash - (coin[idx].first * i) >= 0)
                       ret += go(cash - (coin[idx].first * i), idx + 1); // 다음 코인 쓰러 간다.
        }
        return ret;
}
int main(void)
{
        memset(cache, -1, sizeof(cache));
        cin >> money;
        cin >> n;
        for (int i = 0; i < n; ++i) {
               int a, b;
               cin >> a >> b;
               coin.push_back(make_pair(a, b));
        }
        cout << go(money, 0);
        return 0;
}
