#include <iostream>
#include <vector>
#include <algorithm>
#include <fstream>
#include <string>
#include <cstring>
#define GO
#define DEBUG

using namespace std;

typedef unsigned long long ull;
/*



*/

bool gcd(ull a, ull b) {
	while (b != 0) {
		ull r = a % b;
		a = b;
		b = r;
	}
	return (a == 1 ? true : false);
}

#include <map>
const ull maxv = 1000000000000000001;
map<ull, bool> m;

int main(void) {

#ifdef GO
	freopen("input.txt", "r", stdin);
#endif
	ull a, b;
	cin >> a >> b;
	ull ob = (b - a + 1) / 2;
	ull cnt = 0;
	vector<pair<ull, ull>> ans;
	for (ull j = a; j <= b; j = ++j) {
		if (m[j] == true) {
			continue;
		}
		bool even = false;
		if (j % 2 == 0) {
			even = true;
		}
		for (ull i = j + 1; i <= b; i++) {
			if (m[i] == true) {
				continue;
			}
			if ((even && i % 2 == 0) || (j != 1 && i%j == 0)) {
				cout << j << endl;
				continue;
			}

			if (m[j] == false && m[i] == false && gcd(j, i)) {
				cnt++;
				ans.push_back({ j,i });
				m[j] = true;
				m[i] = true;
				if (cnt != ob) {
					break;
				}
			}
			if (cnt == ob) {
				cout << "YES" << '\n';
				for (int k = 0; k < ans.size(); ++k) {
					cout << ans[k].first << ' ' << ans[k].second << '\n';
				}
				return 0;
			}
		}
	}

	cout << "NO\n";


	return 0;
}