#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

typedef long long ll;
int main(void) {
	int n, m, q;
	cin >> n >> m >> q;
	string s, t;
	cin >> s >> t;
	int a, b;
	for (int i = 0; i < q; ++i) {
		cin >> a >> b;
		if (b - a < m-1) {
			cout << 0 << endl;
			continue;
		}
		int cnt = 0;
		for (int k = a-1; k < b; ++k) {
			bool ch = false;
			bool fullcount = false;
			for (int j = 0; j < m; ++j) {
				if (s[k+j] != t[j] || k+j >b-1)	{
					ch = true;
					break;
				}
				if (j == m - 1) {
					fullcount = true;
				}
			}
			if (!ch && fullcount) {
				cnt++;
			}
		}
		cout << cnt << endl;
	}
	return 0;
}