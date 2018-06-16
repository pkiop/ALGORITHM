#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <cstring>
#include <queue>

using namespace std;

bool arr[101][101];

int main(void) {
	int t;
	cin >> t;
	int a, b;
	while (t--) {
		cin >> a >> b;
		for (int i = a; i < a + 10; ++i) {
			for (int j = b; j < b + 10; ++j) {
				arr[i][j] = true;
			}
		}
	}
	int cnt = 0;
	for (int i = 1; i <= 100; ++i) {
		for (int j = 1; j <= 100; ++j) {
			if (arr[i][j]) {
				cnt++;
			}
		}
	}
	cout << cnt;
	return 0;
}