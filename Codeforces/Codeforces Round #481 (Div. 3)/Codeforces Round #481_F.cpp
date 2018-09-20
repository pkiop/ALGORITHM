#include <iostream>
#include <vector>
#include <algorithm>
#include <fstream>
#include <string>
#include <cstring>
#define GO
#define DEBUG

using namespace std;

/*

5 21
-3 2 -4 -1 -5

*/
int anscnt[200001];
int reserve[200001];
int main(void) {

#ifdef GO
	freopen("input.txt", "r", stdin);
#endif
	vector<pair<int, int> > arr;

	int n, k;
	cin >> n >> k;
	int temp;
	for (int i = 1; i <= n; ++i) {
		cin >> temp;
		arr.push_back({ temp, i });
		reserve[i] = temp;
	}


	sort(arr.begin(), arr.end());
#ifdef DEBUG
	for (int i = 0; i < n; ++i) {
		cout << arr[i].first << ' ' << arr[i].second << endl;
	}
#endif
	int store = 0; // 같은것 몇갠지 새서 저장
	for (int i = 1; i < n; ++i) {
		if (arr[i].first > arr[i - 1].first) {
			anscnt[arr[i].second] = anscnt[arr[i - 1].second] + 1 + store;
			store = 0;
		}
		else {
			anscnt[arr[i].second] = anscnt[arr[i - 1].second];
			store++;
		}
	}
#ifdef DEBUG
	for (int i = 1; i <= n; ++i) {
		cout << anscnt[i] << ' ';
	}
	cout << endl;
#endif
	int t1, t2;
	for (int i = 0; i < k; ++i) {
		cin >> t1 >> t2;
		if (reserve[t1] > reserve[t2]) {
			anscnt[t1]--;
		}
		else if (reserve[t1] < reserve[t2]) {
			anscnt[t2]--;
		}
		else {
			//do nothing
		}
	}

	for (int i = 1; i <= n; ++i) {
		cout << anscnt[i] << ' ';
	}
	return 0;

}