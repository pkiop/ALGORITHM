#include <iostream>
#include <algorithm>
#include <cstring>
#include <limits.h>

using namespace std;

int table[10001];
int cache[10001];
bool visited[10001];
int dx[] = { 1,-1,0,0 };
int dy[] = { 0,0,1,-1 };
int n;

int go(int money) {
	//cout << money << endl;
	if (money == 0) {
		return cache[money];
	}
	if (money < 0) {
		return 10001;
	}
	int& ret = cache[money];
	if (ret != -1) {
		return ret;
	}

	cache[money] = INT32_MAX;

	for (int i = 0; i < n; ++i) {
		ret = min(ret, 1 + go(money - table[i]));
	}
	return ret;
}

int main(void) {

	memset(cache, -1, sizeof(cache));
	int money;
	cin >> n >> money;
	for (int i = 0; i < n; ++i) {
		cin >> table[i];
	}
	int ans = go(money);
	cout << (ans>10000 ? -1 : ans+1) << endl;;

	return 0;
}