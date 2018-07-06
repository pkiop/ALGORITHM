#include <iostream>
#include <algorithm>
#include <queue>
#include <string>
#include <cstring>

using namespace std;

int dp[1000001];

int go(int n) {
	if (n == 1) {
		return 0;
	}
	if (dp[n] != -1) {
		return dp[n];
	}

	int& ret = dp[n];

	
	ret = go(n - 1) + 1;

	if (n % 2 == 0) {
		ret = min(ret, go(n / 2) + 1);
	}

	if (n % 3 == 0) {
		ret = min(ret,go(n / 3)+1);
	}
	
	



	return ret;

}

int main(void) {
	memset(dp, -1, sizeof(dp));
	int n;
	cin >> n;
	cout << go(n) << endl;
	
	return 0;
}