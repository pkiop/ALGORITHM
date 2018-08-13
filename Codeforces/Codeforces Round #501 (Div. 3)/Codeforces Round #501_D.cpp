#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

typedef long long ll;
int main(void) {
	ll n, k, s;
	cin >> n >> k >> s;
	
	if ((n - 1) * k < s ||k > s) {
		cout << "NO" << endl;
		return 0;
	}

	ll kk = k;
	ll ss = s;

	vector<ll> ans;
	bool ansmax = true;
	while ((n - 1) + kk <= ss) {
		ss -= n - 1;
		if (ansmax) {
			ans.push_back(n);
		}
		else {
			ans.push_back(1);
		}
		ansmax = !ansmax;
		kk--;
	}

	ll diff = ss - (kk - 1);
	ll loca = -1;
	if (kk != 0) {
		if (!ansmax) {
			ans.push_back(n - diff);
			loca = n - diff;
		}
		else {
			ans.push_back(1 + diff);
			loca = 1 + diff;
		}
	}
	ansmax = !ansmax;

	for (int i = 0; i < kk - 1; ++i) {
		if (ansmax) {
			loca = loca + 1;
		}
		else {
			loca = loca - 1;
		}
		ans.push_back(loca);
		ansmax = !ansmax;
	}
	cout << "YES" << endl;
	for (int i = 0; i < ans.size(); ++i) {
		cout << ans[i] << ' ';
	}
	return 0;
}