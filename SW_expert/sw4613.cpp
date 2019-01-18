#include <iostream>
#include <vector>
#include <algorithm>
#include <fstream>
#include <string>
#include <cstring>

#define GO

using namespace std;

/*
5 21
-3 2 -4 -1 -5
*/
string arr[51];
vector<vector<int> > numbergenerator(int n) {
	vector<vector<int> > ret;
	vector<int> temp;
	for (int i = 1; i < n; ++i) {
		for (int j = 1; j < n-i; ++j) {
			for (int k = 1; k < n-j; ++k) {
				if (i + j + k == n) {
					temp.push_back(i);
					temp.push_back(j);
					temp.push_back(k);
					ret.push_back(temp);
					temp.clear();
				}
			}
		}
	}
	return ret;
}

int main(void) {

#ifdef GO
	freopen("input.txt", "r", stdin);
#endif

	int t;
	cin >> t;
	for (int T = 1; T <= t; ++T) {
		int n, m;
		cin >> n >> m;
		for (int i = 0; i < n; ++i) {
			arr[i].clear();
		}
		vector<vector<int> > numbers;
		numbers = numbergenerator(n);
		for (int i = 0; i < n; ++i) {
			cin >> arr[i];
		}

		int cnt = 0;
		int minimum = 999999;
		for (auto numberarr : numbers) {
			cnt = 0;
			for (int i = 0; i < numberarr[0]; ++i) {
				for (int j = 0; j < m; ++j) {
					if (arr[i][j] != 'W') {
						cnt++;
					}
				}
			}
			for (int i = numberarr[0]; i < numberarr[0] + numberarr[1]; ++i) {
				for (int j = 0; j < m; ++j) {
					if (arr[i][j] != 'B') {
						cnt++;
					}
				}
			}
			for (int i = numberarr[0] + numberarr[1]; i < numberarr[0] + numberarr[1] + numberarr[2]; ++i) {
				for (int j = 0; j < m; ++j) {
					if (arr[i][j] != 'R') {
						cnt++;
					}
				}
			}
			minimum = min(minimum, cnt);
		}
		cout << '#' << T << ' ' << minimum << endl;
	}

	return 0;
}