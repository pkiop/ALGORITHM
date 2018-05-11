


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
       int n;
       cin >> n;
       int num = 5;
       int ge = 7;
       for (int i = 1; i < n; ++i) {
               num = (num + ge)%45678;
               ge += 3;
       }
       cout << num % 45678 << endl;
       return 0;
}
//5
// 7 10 13 ...
