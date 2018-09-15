#include <iostream>
#include <fstream>
#include <algorithm>

using namespace std;

typedef long long ll;

ll arr[200001];

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

#ifdef GO
	freopen("input.txt", "r", stdin);
#endif

	int n;
	cin >> n;

	for (int i = 0; i < n; ++i) {
		cin >> arr[i];
	}
	int maxcnt = 0;
	//1234567
	for (int i = 0; i < n; ++i) {
		int j = i;
		while (arr[j] * 2 >= arr[j + 1] && j < n-1) {
			j++;
		}
		maxcnt = max(maxcnt, j - i + 1);
		i = j;
	}
	cout << maxcnt;
	return 0;
}