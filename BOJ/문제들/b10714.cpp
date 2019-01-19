#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>

using namespace std;

long long dp[2001][2001];
int arr[2001];
int n;

long long go(int l, int r, bool ch) {
	if (dp[l][r] != -1)
		return dp[l][r];

	if (l == r) {
		if (ch) return dp[l][r] = 0;
		return dp[l][r] = arr[l];
	}

	if (ch) {
		if (arr[l]>arr[r]) {
			return dp[l][r] = go((l + 1) % n, r, false);
		}
		else {
			return dp[l][r] = go(l, (r + n - 1) % n, false);
		}
	}
	return dp[l][r] = max(go((l + 1) % n, r, true) + arr[l], go(l, (r + n - 1) % n, true) + arr[r]);
}
int main() {

#ifdef GO
	freopen("input.txt", "r", stdin);
#endif
	cin >> n;
	for (int i = 0; i < n; ++i) {
		cin >> arr[i];
	}

	memset(dp, -1, sizeof(dp));

	long long ret = 0;
	for (int i = 0; i < n; i++) {
		ret = max(ret, go((i + 1) % n, (i + n - 1) % n, true) + arr[i]);
	}
	cout << ret << endl;
	return 0;
}