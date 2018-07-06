#include <iostream>
#include <algorithm>
#include <queue>
#include <string>
#include <cstring>

using namespace std;

int arr[1001][3];
int dp[1001][3];
int n;

int go(int src,int thiscolor) {
	if (src == n) {
		return 0;
	}

	int& ret = dp[src][thiscolor];
	if (ret != -1) {
		return ret;
	}
	ret = 99999999;
	int val = arr[src][thiscolor];

	for (int color = 0; color < 3; ++color) {
		if (color != thiscolor) {
			ret = min(ret,val + go(src + 1, color));
		}
	}
	return ret;
}



int main(void) {
	memset(dp, -1, sizeof(dp));
	cin >> n;
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < 3; ++j) {
			cin >> arr[i][j];
		}
	}
	cout <<min(go(0, 0), min(go(0, 1), go(0, 2)));
	return 0;
}