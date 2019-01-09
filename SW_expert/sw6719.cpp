#include <iostream>
#include <algorithm>
#include <cstring>
 
using namespace std;
 
int arr[201];
int idx = 0;
int main(void) {
    int t;
    cin >> t;
    while (t--) {
        memset(arr, -1, sizeof(arr));
        idx++;
        int n,k;
        cin >> n >> k;
        for (int i = 0; i < n; ++i) {
            cin >> arr[i];
        }
        sort(arr, arr + n);
        double ans = 0;
        for (int i = n-k; i < n; ++i) {
            ans = (ans + double(arr[i])) / 2;
        }
        cout << '#' << idx << ' ' << ans << endl;
         
    }
    return 0;
}