#include <iostream>
#include <algorithm>
#include <cstring>
#include <limits.h>

using namespace std;

int twofive[2] = { 5,2 };
int cache[100001];
int n;

int go(int money) {
	cout << money << '\n';
	if (money == 0) {
		return cache[money];
	}
	if (money < 0) {
		return 999999;
	}
	
	int& ret = cache[money];
	if (ret != -1) {
		return ret;
	}
	cache[money] = 999999;
	for (int i = 0; i < 2; ++i) {
		ret = min(ret, go(money - twofive[i]) + 1);
	}
	return ret;
}

int main(void) {

	memset(cache, -1, sizeof(cache));
	cin >> n;
	int ans = go(n) + 1;
	
	cout << (ans > 999990 ? -1 : ans) << endl;
	return 0;
}