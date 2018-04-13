#include <iostream>
#include <algorithm>
#include <cstring>
#include <limits.h>
#include <stack>

using namespace std;

int stb[10001]; // single table
int scache[100001]; // single cache
int tb[1001][1001];
int cache[1001][1001];
int n;

int go(int idx) {
	
	if (scache[idx] != -1) {
		return scache[idx];
	}

	int& ret = scache[idx] = 1;
	for (int i = idx+1; i < n; ++i) {
		if (stb[idx] < stb[i]) {
			ret = max(ret,go(i) + 1);
		}
	}
	return ret;
}

int main(void) {
	memset(scache, -1, sizeof(scache));

	cin >> n;
	for (int i = 0; i < n; ++i) {
		cin >> stb[i];
	}
	int ans = 0;
	for (int i = 0; i < n; ++i) {

		ans = max(ans, go(i));
	}
	
	cout << ans;
	return 0;
}