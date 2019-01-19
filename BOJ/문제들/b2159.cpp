#include <iostream>
#include <cstdio>
#include <string>
#include <vector>
#include <algorithm>
#include <cstring>
#include <cassert>

using namespace std;

typedef long long ll;

ll dp[100001][5];
ll x[100001], y[100001], n;
int dx[] = { 0,1,-1,0,0 };
int dy[] = { 0,0,0,1,-1 };

ll f(int k, int pos) {
	if (k == n) return 0;
	ll& ret = dp[k][pos];
	if (ret != -1) {
		return ret;
	}
	ll MIN = abs((x[k] + dx[pos]) - x[k + 1]) + abs((y[k] + dy[pos]) - y[k + 1]) + f(k + 1, 0);

	for (int i = 1; i < 5; ++i) {
		MIN = min(MIN, abs((x[k] + dx[pos]) - (x[k + 1] + dx[i])) + abs((y[k] + dy[pos]) - (y[k + 1] + dy[i])) + f(k + 1, i));
	}
	return ret = MIN;
}

int main(void) {
	cin >> n;
	memset(dp, -1, sizeof(dp));
	for (int i = 0; i <= n; ++i) {
		cin >> x[i] >> y[i];
	}
	cout << f(0, 0);
	return 0;
}
