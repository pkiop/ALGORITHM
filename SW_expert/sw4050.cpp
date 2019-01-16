#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;

int arr[100001];

int main(void) {
	int t, idx = 1;
	cin >> t;
	while (t--) {
		memset(arr, 0, sizeof(arr));
		int n;
		cin >> n;
		for (int i = 0; i < n; ++i) {
			cin >> arr[i];
		}
		sort(arr, arr + n);
		reverse(arr, arr + n);
		//for (int i = 0; i < n; ++i) {
		//	cout << arr[i] << ' ';
		//}
		int ans = 0;
		for (int i = 0; i < n-2; i += 3) {
			ans += arr[i] + arr[i + 1];
		}
		if (n % 3 == 1) {
			ans += arr[n - 1];
		}
		if (n % 3 == 2) {
			ans += arr[n - 1] + arr[n - 2];
		}

		cout << '#' << idx++ << ' ' << ans << endl;
	}
	return 0;
}