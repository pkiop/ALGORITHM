

#include <iostream>
#include <stack>
#include <queue>
#include <algorithm>
#include <string>
#include <set>
#include <cstring>
using namespace std;
typedef long long ll;
int main(void)
{
       ll num;
       cin >> num;
       ll cnt = 1;
       while (num > 0) {
               num -= cnt;
               cnt++;
       }
       if (num == 0) {
               cout << cnt -1 << endl;
       }
       else {
               cout << cnt - 2 << endl;
       }
       return 0;
}
