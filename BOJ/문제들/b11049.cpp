#include <iostream>
#include <cstring>
#include <vector>
#include <limits>
#include <algorithm>
using namespace std;
vector<pair<int, int>> p;
int cache[510][510];
int go(int x, int y) {
       if (x == y) {
               return 0;
       }
       int& ret = cache[x][y];
       if (ret != -1) {
               return ret;
       }
       int mm = INT32_MAX;
       
       //전체는 처음 x부터 i까지와 i+1과 끝 y까지로 나눌 수 있다.
       for (int i = x; i < y; ++i) {
               mm = min(mm, go(x, i) + go(i + 1, y) + p[x].first * p[i].second * p[y].second);

 //여기는 나눠지고 나면 마지막 합쳐졌을 때를 생각하면 나오는 식
       }
       return ret = mm;
}
int main(void)
{
       int n;
       cin >> n;
       memset(cache, -1, sizeof(cache));
       for (int i = 0; i < n; ++i) {
               int a, b;
               cin >> a >> b;
               p.push_back(make_pair(a, b));
       }
       cout << go(0, n - 1);
       return 0;
}