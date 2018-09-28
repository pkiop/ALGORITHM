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

2
5
3 2
1 4
4 1
2 3
5 5
7
3 6
7 3
4 2
1 4
5 7
2 5
6 1

*/


int main(void) {

#ifdef GO
	freopen("input.txt", "r", stdin);
#endif
	int t;
	cin >> t;
	while (t--) {
		vector<pair<int, int> > arr;
		int n;
		cin >> n;
		int a, b;
		for (int i = 0; i < n; ++i) {
			cin >> a >> b;
			arr.push_back({ a,b });
		}
		sort(arr.begin(), arr.end());

		int cnt = 1;
		int han = arr[0].second;
		for (int i = 1; i < n; ++i) {
			if (arr[i].second < han) {
				han = arr[i].second;
				cnt++;
			}
		}
		cout << cnt << endl;
		arr.clear();
	}


	

	return 0;
}