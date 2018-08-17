#include <iostream>
#include <cstdio>
#include <string>
#include <vector>
#include <algorithm>
#include <cstring>
#include <cassert>

using namespace std;

int arr[101];
int dp[101][51];
int sum[101];
int M = -1111111111;
int n, m;

int f(int x, int y) {
	if (y == 0) return 0;
	if (x > n || y < 0) return M;

	int& ret = dp[x][y];
	if (ret != M) return ret;
	ret = -100000000; // 있고없고차이
	ret = max(ret, f(x + 1, y));
	for (int i = 0; i <= n - x; ++i) {
		ret = max(ret, f(x + i + 2, y - 1) + sum[x + i] - sum[x - 1]);
	}
	return ret;

}

int main(void) {
	
	for (int i = 0; i < 51; ++i) {
		for (int j = 0; j < 101; ++j) {
			dp[j][i] = M;
		}
	}
	scanf("%d %d", &n, &m);
	for (int i = 1; i <= n; ++i) {
		scanf("%d", &arr[i]);
	}
	for (int i = 1; i <= n; ++i) {
		sum[i] = sum[i - 1] + arr[i];
	}
	printf("%d", f(1, m));
	return 0;

}