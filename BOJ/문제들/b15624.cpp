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
const int mod = 1000000007;

int main(void) {
	int ans = 0;
	int a = 1;
	int b = 1;
	for (int i = 0; i < n; ++i) {
		ans += a%mod + b%mod;
		a = ans;
		b = a;
	}
	cout << ans%mod;
	
	
	
	return 0;
}