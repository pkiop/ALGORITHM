#include <iostream>
#include <algorithm>
#include <cstring>
#include <limits.h>
#include <stack>

using namespace std;

typedef long long ll;

ll stb[10001]; // single table
ll sche[100001]; // single cache
int tb[1001][1001];
int cache[1001][1001];
int n,m;


int main(void) {
	
	cin >> n >> m;
	if (n == m || m == 0) {
		cout << 1 << endl;
		return 0;
	}
	cache[0][0] = cache[1][0] = cache[1][1] = 1;
	for (int i = 2; i <= n; ++i) {
		cache[i][0] = cache[i][i] = 1;
		for (int j = 1; j <= i-1; ++j) {
			cache[i][j] = cache[i - 1][j - 1]%10007 + cache[i - 1][j]%10007;
		}
	}
	cout << cache[n][m]%10007;
	
	return 0;
}