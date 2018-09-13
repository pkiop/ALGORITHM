/*

3
6
3000 2700 2800 2200 2500 1900
2800 2750 2995 1800 2600 2000
3
1 2 3
3 2 1
4
2 3 4 5
1 2 3 4


ans == 
5
3
3
*/
#define GO

#include <iostream>
#include <fstream>
#include <algorithm>
#include <cstring>
#include <vector>

#define MAX_N 100001

using namespace std;

int n, e[MAX_N], m[MAX_N];

int heat() {
	vector<pair<int, int> > order;
	for (int i = 0; i < n; ++i) {
		order.push_back(make_pair(-e[i], i));
	}
	sort(order.begin(), order.end());

	int ret = 0, beginEat = 0;
	for (int i = 0; i < n; ++i) {
		int box = order[i].second;
		beginEat += m[box];
		ret = max(ret, beginEat + e[box]);
	}
	return ret; 
}

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

#ifdef GO
	freopen("input.txt", "r", stdin);
#endif
	int t; 
	cin >> t;
	while (t--) {
		cin >> n;
		for (int i = 0; i < n; ++i) {
			cin >> m[i];
		}
		for (int i = 0; i < n; ++i) {
			cin >> e[i];
		}
		cout << heat() << '\n';
	}
	
	return 0;
}