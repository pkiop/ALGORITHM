#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;

int day[1001];
int val[1001];
int dp[1001];
int n; //n 일까지

int go(int idx) {
	/*cout << idx << endl;*/
	if (idx > n) {
		return 0;
	}
	int& ret = dp[idx];
	if (ret != -1) {
		return ret;
	}
	if (idx + day[idx] <= n+1) { // 8일째에 3일일하라고 하면 10일까지 일하는 거니까 +1을 하던 가 -1을 하던가 
		ret = max(go(idx + day[idx]) + val[idx], go(idx + 1));
	}
	else {
		ret = go(idx + 1);
	}
	
	return ret;
}

int main(void) {
	memset(dp, -1, sizeof(dp));
	cin >> n;
	// i 가 의미하는 것 : i일째
	for (int i = 1; i <= n; ++i) {
		cin >> day[i];
		cin >> val[i];
	}// input 끝
	cout << go(1) << endl; //1일차 시작

	/*for (int i = 1; i <= n; ++i) {
		cout << dp[i] << ' ';
	}*/
	return 0;
	
}