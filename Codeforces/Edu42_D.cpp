#include <iostream>
#include <vector>
#include <limits.h>
#include <string>
#include <algorithm>
#include <cstring>

using namespace std;

typedef unsigned long long ull;

struct tb {
	ull val;
	int idx;
};

bool cmp(const tb& u, const tb& v) {
	if (u.val < v.val) {
		return true;
	}
	else if (u.val == v.val) {
		return u.idx < v.idx;
	}
	return false;
}

bool cmpidx(const tb& u, const tb& v) {
	if (u.val == 0) {
		return false;
	}
	if (v.val == 0) {
		return true;
	}
	if (u.idx < v.idx) {
		return true;
	}
	return false;
}

int main(void)
{
	int n;
	cin >> n;
	tb tb1[150001];
	for (int i = 0; i<n; ++i) {
		int n;
		cin >> n;
		tb1[i].val = n;
		tb1[i].idx = i;
	}
	sort(tb1, tb1 + n, cmp);
	
	
	bool doo = true;
	while (doo == true) {
		doo = false;
		for (int i = 0; i < n - 1; ++i) {
			if ((tb1[i].val == tb1[i + 1].val) && (tb1[i].val != 0)) {
				tb1[i].val = 0;
				tb1[i + 1].val += tb1[i + 1].val;
				doo = true;
			}
		}
		sort(tb1, tb1 + n, cmp);
	}

	sort(tb1, tb1 + n, cmpidx);
	vector<ull> ans;
	for (int i = 0; i<n; ++i) {
		if (tb1[i].val != 0) {
			ans.push_back(tb1[i].val);
		}
	}
	
	int len = ans.size();
	cout << len << '\n';
	for (int i = 0; i<len; ++i) {
		printf("%lld", ans[i]);
		if (i != len - 1) {
			cout << ' ';
		}
	}
	

	return 0;

}