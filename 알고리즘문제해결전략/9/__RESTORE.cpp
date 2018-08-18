#include <iostream>
#include <cstdio>
#include <string>
#include <vector>
#include <algorithm>
#include <cstring>
#include <cassert>

using namespace std;

const int MAX_N = 15;
int k;
string word[MAX_N];
int cache[MAX_N][1 << MAX_N], overlap[MAX_N][MAX_N];
int restore(int last, int used) {
	if (used == (1 << k) - 1) return 0;
	int& ret = cache[last][used];
	if (ret != -1) return ret;
	ret = 0;
	for (int next = 0; next < k; ++next)
		if (used & (1 << next) == 0) {
			int cand = overlap[last][next] + restore(next, used + (1 << next));
			ret = max(ret, cand);
		}
	return ret;
}

string reconstruct(int last, int used) {
	if (used == (1 << k) - 1) return "";
	for (int next = 0; next < k; ++next) {
		if (used & (1 << next)) continue;
		int ifUsed = restore(next, used + (1 << next)) + overlap[last][next];
		if (restore(last, used) == ifUsed)
			return (word[next].substr(overlap[last][next]) + reconstruct(next, used + (1 << next)));
	}

}

int main(void) {
	int t;
	cin >> t;
	while (t--) {
		memset(cache, -1, sizeof(cache));
		cin >> k;
		for (int i = 0; i < k; ++i) {
			cin >> word[i];
		}
		int temp = restore(0, 0);
		cout << reconstruct(temp, (temp<<1)) << endl;
	}
}
