#include <iostream>
#include <cstdio>
#include <string>
#include <vector>
#include <algorithm>
#include <cstring>
#include <cassert>

using namespace std;


int n, w;

struct dot {
	int x, y;
};

dot first[1001], second[1001];
int dp[1001][1001];

int f(int c1, int c2) {
	if (c1 == w || c2 == w)
		return 0;

	int& ret = dp[c1][c2];
	if (ret != -1) {
		return ret;
	}

	int np = max(c1, c2) + 1;
	int n1 = abs(first[c1].x - first[np].x) + abs(first[c1].y - first[np].y);
	int n2 = f(np, c2) +n1;

	int m1 = abs(second[c2].x - second[np].x) + abs(second[c2].y - second[np].y);
	int m2 = f(c1, np) + m1;

	return ret = min(n2, m2);
}

vector<int> v;
void tracking(int c1, int c2) {
	if (c1 == w || c2 == w)
		return;

	int np = max(c1, c2) + 1;
	int n1 = abs(first[c1].x - first[np].x) + abs(first[c1].y - first[np].y);
	int n2 = dp[np][c2] + n1;

	int m1 = abs(second[c2].x - second[np].x) + abs(second[c2].y - second[np].y);
	int m2 = dp[c1][np] + m1;

	if (n2 > m2) {
		v.push_back(2);
		tracking(c1, np);
	}
	else {
		v.push_back(1);
		tracking(np, c2);
	}
}

int main(void) {
	cin >> n >> w;
	
	first[0] = { 1,1 };
	second[0] = { n,n };
	for (int i = 1; i <= w; ++i) {
		cin >> first[i].x >> first[i].y;
		second[i] = { first[i].x, first[i].y };
	}

	memset(dp, -1, sizeof(dp));
	cout << f(0, 0) << '\n';

	tracking(0, 0);
	for (auto a : v) {
		cout << a << '\n';
	}
	return 0;
}
