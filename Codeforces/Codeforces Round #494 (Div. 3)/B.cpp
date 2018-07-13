#include <iostream>
#include <algorithm>
#include <queue>
#include <string>
#include <cstring>
#include <set>

using namespace std;

int main(void) {
	int a, b, x;
	cin >> a >> b >> x;
	bool zerobig = false;
	if (a > b) {
		zerobig = true;
	}
	vector<int> ans;
	if (zerobig) {
		ans.push_back(0);
		a--;
	}
	else {
		ans.push_back(1);
		b--;
	}
	while (x-- != 1) {
		if (ans[ans.size() - 1] == 0) {
			ans.push_back(1);
			b--;
		}
		else {
			ans.push_back(0);
			a--;
		}
	}
	if (ans[ans.size() - 1] == 0 && a != 0) {
		for (int i = 0; i < a; ++i) {
			ans.push_back(0);
		}
		a = 0;
	}

	if (ans[ans.size() - 1] == 1 && b != 0) {
		for (int i = 0; i < b; ++i) {
			ans.push_back(1);
		}
		b = 0;
	}
	
	if (ans[ans.size() - 1] == 1 && a != 0) {
		for (int i = 0; i < a; ++i) {
			ans.push_back(0);
		}
	}

	if (ans[ans.size() - 1] == 0 && b != 0) {
		for (int i = 0; i < b; ++i) {
			ans.push_back(1);
		}
	}

	for (int i = 0; i < ans.size(); ++i) {
		cout << ans[i];
	}
}



