#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main(void)
{
	int n,nn;
	cin >> n;
	nn = n;
	long long ans = 0;
	vector<int> plus;
	vector<int> minus;
	bool in_zero = false;
	while (nn--) {
		int k;
		cin >> k;
		if (k == 1) {
			ans += 1;
			continue;
		}
		if (k > 0) {
			plus.push_back(k);
			continue;
		}
		if (k < 0) {
			minus.push_back(k);
			continue;
		}
		if (k == 0) {
			in_zero = true;
			continue;
		}
	}
	int lenp = plus.size();
	sort(plus.begin(), plus.end());
	if (lenp % 2 != 0) {
		lenp--;
		ans += plus[lenp];
	}
	for (int i = 0; i < lenp-1; i+=2) {
		ans += plus[i] * plus[i + 1];
	}

	int lenm = minus.size();
	sort(minus.begin(), minus.end());
	if (lenm % 2 != 0) {
		if (in_zero) {
			lenm--;
		}
		else {
			lenm--;
			ans += minus[lenm];
		}
	}
	for (int i = 0; i < lenm - 1; i += 2) {
		ans += minus[i] * minus[i + 1];
	}
	cout << ans << endl;
	return 0;
}