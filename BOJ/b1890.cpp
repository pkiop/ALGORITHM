//1890 점프
#include <iostream>
#include <algorithm>

using namespace std;
typedef long long ll;
ll tb[1001][1001]; // tb == table
ll cch[1001][1001]; // cch == cache
ll n, cnt = 0;

ll go(ll x, ll y) {
       if (x == y && y == n - 1) {
              return 1;
       }
       /*if (tb[x][y] == 0) {
       cch[x][y] = -1;
       }*/

       ll& ret = cch[x][y];

       if (ret != -1) {
              return ret;
       }
       ret = 0;
       ll next = tb[x][y];
       if (next > 0) {
              if (x + next < n) {
                     ret += go(x + next, y);
              }
              if (y + next < n) {
                     ret += go(x, y + next);
              }
       }
       return ret;
}

void process() {
       cin >> n;
       for (int i = 0; i < n; ++i) {
              for (int j = 0; j < n; ++j) {
                     cin >> tb[i][j];
                     cch[i][j] = -1; // cahce init
              }
       }


       //cout << (cch[n-1][n-1]==1 ? "YES" : "NO") << endl;
       cout << go(0, 0) << endl;
       return;
}


int main(void)
{

       process();

       return 0;
}