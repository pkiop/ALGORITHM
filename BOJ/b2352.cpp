#include <iostream>
#include <cstring>
#include <vector>
#include <limits>
#include <algorithm>
using namespace std;
int tb1[40001];
int cache[40001];
int n;
int main(void)
{
       
       cin >> n;
       for (int i = 0; i < n; ++i) {
               cin >> tb1[i];
       }
       
       
       cache[0] = tb1[0];
       int size = 0;
       for (int i = 1; i < n; ++i) {
               if (cache[size] < tb1[i]) {
                      size++;
                      cache[size] = tb1[i];
                      continue;
               }
               int it = lower_bound(cache, cache + size, tb1[i]) - cache;
               cache[it] = tb1[i];
       }
       cout << size+1 << endl;
       
       return 0;
}