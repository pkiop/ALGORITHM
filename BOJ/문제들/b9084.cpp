#include <iostream>
#include <vector>
#include <cstring>

using namespace std;

int n;
int money;
int arr[21];
int cnt;
int cache[10011][100];

int go(int sum,int index) {
       
       if (sum == 0) {
             return 1;
       }
       if (sum < 0) {
             return 0;
       }
       if (cache[sum][index] != -1) {
             return cache[sum][index];
       }
       cache[sum][index]++;
       int& ret = cache[sum][index];
       for (int i = index; i < n; ++i) {
             ret += go(sum - arr[i],i);
       }
       return ret;
}

int main(void)
{
       int t;
       cin >> t;
       while (t--) {
             memset(arr, 0, sizeof(arr));
             memset(cache, -1, sizeof(cache));
             cnt = 0;
             cin >> n;
             for (int i = 0; i < n; ++i) {
                    cin >> arr[i];
             }
             cin >> money;
             cout << go(money,0) << endl;
             
       }
       return 0;
}