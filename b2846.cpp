#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main(void) {
	int n;
	cin >> n;
	vector<int> tb1(n+1);
	for (int i = 0; i < n; ++i) {
		cin >> tb1[i];
	}
	
	int st = tb1[0]; // 처음부터 끝까지 오르막길일때 처리
	tb1[n] = 0;
	int maxv = 0;
	vector<int>::iterator it;
	for (it = tb1.begin() + 1; it != tb1.end(); ++it) {
		if (*it <= *(it-1)) {
			maxv = max(maxv, *(it-1) - st);
			//cout << maxv << endl;
			st = *it;
		}
	}
	cout << maxv << endl;
	return 0;
}