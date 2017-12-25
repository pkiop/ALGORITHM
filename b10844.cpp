#include <iostream>

using namespace std;
#define DIV 1000000000
int d[101][10];

int main() {
	int n;
	cin >> n;
	for (int i = 1; i <= 9; ++i) {
		d[1][i] = 1;
	}

	for (int i = 2; i <= n; ++i) {
		for (int j = 0; j <= 9; ++j) {
			if (j >= 1) {
				d[i][j] += d[i - 1][j - 1];
				d[i][j] %= DIV;
			}
			if (j <= 8) {
				d[i][j] += d[i - 1][j + 1];
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