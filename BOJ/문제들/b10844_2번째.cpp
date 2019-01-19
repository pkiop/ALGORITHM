#include <iostream>

using namespace std;

const int mod = 1000000000;

long long dp[101][10];
int main(void) {
	int n;
	cin >> n;
	dp[1][0] = 0;
	for (int i = 1; i < 10; ++i) {
		dp[1][i] = 1;
	}

	for (int i = 2; i <= n; ++i) {
		for (int j = 0; j < 10; ++j) {
			if (j == 0) {
				dp[i][j] = dp[i - 1][1];
			}
			else if (j == 9) {
				dp[i][j] = dp[i - 1][8];
			}
			else {
				dp[i][j] = dp[i - 1][j - 1]%mod + dp[i - 1][j + 1]%mod;
			}
		}
	}
	long long ans = 0;
	for (int i = 0; i < 10; ++i) {
		ans += dp[n][i];
	}
	cout << ans%mod << endl;
	return 0;
}