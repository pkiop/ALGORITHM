#include <iostream>

using namespace std;
#define DIV 10007
int d[1001][10];

int main() {
	int n;
	cin >> n;
	for (int i = 0; i <= 9; ++i) {
		d[1][i] = 1;
	}

	for (int i = 2; i <= n; ++i) {
		for (int j = 0; j <= 9; ++j) {
			for (int k = 0; k <= j; ++k) {
				d[i][j] += d[i - 1][k];
				d[i][j] %= DIV;
			}
		}
	}

	long long ans = 0;
	for (int i = 0; i <= 9; ++i) {
		ans += d[n][i];
		ans %= DIV;
	}
	cout << ans;
	return 0;
}