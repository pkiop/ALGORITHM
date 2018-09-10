#include <iostream>
#include <cstring>
using namespace std;

const int mod = 1000000000;
const int full = (1 << 10) - 1;

long long dp[101][10][1 << 10];

int main(void) {
	int n;
	cin >> n;

	for (int i = 1; i < 10; ++i) {
		dp[1][i][1 << i] = 1;
	}

	for (int i = 2; i <= n; ++i) {
		for (int j = 0; j < 10; ++j) {
			for (int k = 0; k <= full; ++k) {
				if (j == 0) {
					dp[i][j][k | (1<<0)] += (dp[i - 1][1][k])%mod;
				}
				else if (j == 9) {
					dp[i][j][k | (1<<j)] += (dp[i - 1][8][k])%mod;
				}
				else {
					dp[i][j][k | (1<<j)] += (dp[i - 1][j-1][k])%mod;
					dp[i][j][k | (1<<j)] += (dp[i - 1][j+1][k])%mod;
				}
			}
		}
	}
	long long ans = 0;
	for (int i = 0; i < 10; ++i) {
		ans += dp[n][i][full] % mod;
	}
	cout << ans%mod << endl;
	return 0;
}