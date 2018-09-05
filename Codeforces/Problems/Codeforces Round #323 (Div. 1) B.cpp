#include <iostream>
#include <cstdio>
#include <string>
#include <vector>
#include <algorithm>
#include <cstring>
#include <cassert>

using namespace std;

int n, m;
int arr[101];
int dp[10000001];

int main(void) {
	memset(dp, -1, sizeof(dp));
	cin >> n >> m;
	for (int i = 0; i < n; ++i) {
		cin >> arr[i];
	}
	int dpmax = 0;
	for (int i = 0; i < n*m; ++i) {
		dp[i] = 1;
		for (int j = 0; j < i; ++j) {
			if (arr[i%n] >= arr[j%n] && dp[i] < dp[j] + 1) {
				dp[i] = dp[j] + 1;
				dpmax = max(dpmax, dp[i]);
			}
		}
	}
	//for (int i = 0; i < m*n; ++i) {
	//	cout << arr[i%n] << ' ';
	//}
	//cout << endl;
	//for (int i = 0; i < m*n; ++i) {
	//	cout << dp[i] << ' ';
	//}
	//cout << endl;
	cout << dpmax << endl;
	return 0;
}