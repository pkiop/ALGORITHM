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

5 3
xyabd

*/

char arr[51];

int main(void) {

#ifdef GO
	freopen("input.txt", "r", stdin);
#endif

	int n, k;
	cin >> n >> k;
	char trash;
	scanf("%c", &trash);
	for (int i = 0; i < n; ++i) {
		scanf("%c", &arr[i]);
	}

	sort(arr, arr + n);
	int idx = 0;
	int sum = int(arr[idx] - 'a' + 1);
	int selcnt = 0;
	idx++;
	selcnt++;
	int bidx = 0;
	while (idx < n && selcnt != k) {
		if (int((arr[idx] - 'a' + 1) - (arr[bidx] - 'a' + 1)) > 1) {
			sum += int(arr[idx] - 'a' + 1);
			bidx = idx;
			selcnt++;
		}
		idx++;
	}
#ifdef DEBUG
	cout << arr << endl;
#endif
	if (selcnt != k) {
		cout << -1 << endl;
		return 0;
	}
	cout << sum << endl;
	return 0;
}