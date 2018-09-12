/*

3
6
3000 2700 2800 2200 2500 1900
2800 2750 2995 1800 2600 2000
3
1 2 3
3 2 1
4
2 3 4 5
1 2 3 4


ans == 
5
3
3
*/
#define GO

#include <iostream>
#include <fstream>
#include <algorithm>
#include <cstring>

using namespace std;

int arr[101];
int arr2[101];

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

#ifdef GO
	freopen("input.txt", "r", stdin);
#endif
	int t;
	cin >> t;
	while (t--) {
		memset(arr, -1, sizeof(arr));
		memset(arr2, -1, sizeof(arr2));
		int n;
		cin >> n;
		for (int i = 0; i < n; ++i) {
			cin >> arr[i];
		}
		for (int i = 0; i < n; ++i) {
			cin >> arr2[i];
		}
		sort(arr, arr + n);
		sort(arr2, arr2 + n);
		reverse(arr, arr + n);
		reverse(arr2, arr2 + n);
	/*	for (int i = 0; i < n; ++i) {
			cout << arr[i] << ' ';
		}*/
		int ans = 0;
		for (int i = 0; i < n; ++i) {
			for (int j = 0; j < n; ++j) {
				//cout << j << endl;
				if (arr2[j] == -1) {
					continue;
				}
				if (arr[i] > arr2[j]) {
					for (int k = n - 1; k >= 0; --k) {
						if (arr2[k] != -1) {
							arr2[k] = -1;
							break;
						}
					}
					break;
				}
				else {
					for (int k = n - 1; k >= 0; --k) {
						//cout << "do ";
						if (arr2[k] >= arr[i]) {
							arr2[k] = -1;
							ans++;
							break;
						}
					}
					break;
				}
			}
		}
		cout << ans << '\n';
	}
	return 0;
}