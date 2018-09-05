#include <iostream>
#include <cstdio>
#include <string>
#include <vector>
#include <algorithm>
#include <cstring>
#include <cassert>

using namespace std;

int dp[1000001];

int main(void) {
	int n;
	cin >> n;
	dp[0] = 0;
	dp[1] = 1;// 1
	dp[2] = 2;// 00 11
	dp[3] = 3;// 000 001 100
	dp[4] = 5;// 0000 0011 1100 1111 1001
	dp[5] = 8;// 00001 00100 10000 00111 11001 10011 11100 11111
	for (int i = 6; i <= n; ++i) {
		dp[i] = dp[i - 1]%15746 + dp[i - 2]%15746;
	}
	cout << dp[n]%15746;
	return 0;



}