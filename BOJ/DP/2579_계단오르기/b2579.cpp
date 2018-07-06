#include <iostream>
#include <algorithm>
#include <queue>
#include <string>
#include <cstring>

using namespace std;

int arr[301];
int dp[301][2];
int n;

int go(int src,int step) {
	if (src > n) {
		return -999999;
	}
	if (src == n) {
		return arr[n];
	}

	if (dp[src][step] != -1) {
		return dp[src][step];
	}

	int& ret = dp[src][step] = 0;
	if (step == 0) {
		ret = max(ret, go(src + 1, 1) + arr[src]);
		ret = max(ret, go(src + 2, 0) + arr[src]);
	}
	if (step == 1) {
		ret = max(ret, go(src + 2, 0) + arr[src]);
	}

	return ret;
}



int main(void) {
	memset(dp, -1, sizeof(dp));
	cin >> n;
	for (int i = 1; i <= n; ++i) {
		cin >> arr[i];
	}
	arr[0] = 0;
	int ans = go(0, 0);
	memset(dp, -1, sizeof(dp));
	ans = max(ans, go(1, 0));
	cout << ans << endl;
	return 0;
}