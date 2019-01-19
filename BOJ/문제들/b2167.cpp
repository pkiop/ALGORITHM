#include <iostream>
#include <algorithm>
#include <cstring>
#include <limits.h>
#include <stack>

using namespace std;

int table[1001][1001];
int cache[1001][1001];
int dx[] = { 1,0,1 };
int dy[] = { 0,1,1 };
int n, m;
int i, j, x, y;

int main(void) {
	cin >> n >> m;
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < m; ++j) {
			cin >> table[i][j];
		}
	}
	int t;
	cin >> t;
	while (t--) {
		cin >> i >> j >> x >> y;
		i -= 1;
		j -= 1;
		x -= 1;
		y -= 1;
		int sum = 0;
		for (int ii = i; ii <= x; ++ii) {
			for (int jj = j; jj <= y; ++jj) {
				sum += table[ii][jj];
			}
		}
		cout << sum << endl;
	}

	return 0;
}