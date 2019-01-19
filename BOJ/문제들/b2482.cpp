#include <iostream>

using namespace std;

const int mod = 1000000003;
int dp[1001][1001];

int main() { 
	int N, K; 
	cin >> N >> K;
	for (int i = 1; i <= N; ++i) 
		dp[i][0] = 1; 
	for (int i = 1; i <= N; ++i) 
		dp[i][1] = i; 
	for (int i = 2; i <= N; ++i) { 
		for (int j = 2; j <= N; ++j) { 
			//dp[i - 2][j - 1] => 색 선택하는 경우
			//dp[i - 1][j]     => 색 선택하지 않는 경우
			dp[i][j] = (dp[i - 2][j - 1] + dp[i - 1][j]) % mod; 
		} 
	}
	cout << (dp[N - 3][K - 1] + dp[N - 1][K]) % mod;
	return 0; 
}

