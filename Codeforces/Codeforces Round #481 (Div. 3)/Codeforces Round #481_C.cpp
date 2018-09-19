#include <iostream>
#include <vector>
#include <algorithm>
#include <fstream>
#include <string>
#define GO

using namespace std;

/*

2 3
5 10000000000
5 6 9999999999

*/

typedef long long ll;

ll arra[200001];
ll arrb[200001];



int main(void) {

#ifdef GO
	freopen("input.txt", "r", stdin);
#endif
	int n, m;
	cin >> n >> m;
	for (int i = 1; i <= n; ++i) {
		cin >> arra[i];
	}
	for (int i = 0; i < m; ++i) {
		cin >> arrb[i];
	}
	ll dominum = 1;
	ll domimin = 1;
	int i = 0;
	vector<pair<ll, ll> > ans;
	while (i < m && dominum <= n) {

		if (arra[dominum] >= arrb[i] - domimin + 1) {
			ans.push_back({ dominum, arrb[i] - domimin + 1 });
			i++;
		}
		else {
			domimin += arra[dominum];
			dominum++;
		}
	}

	for (auto y : ans) {
		cout << y.first << ' ' << y.second << '\n';
	}
	return 0;

	

}