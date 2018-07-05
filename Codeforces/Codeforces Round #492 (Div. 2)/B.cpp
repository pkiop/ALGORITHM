#include <iostream>
#include <algorithm>

using namespace std;

int arr[100001];

int main(void) {
	int n;
	cin >> n;
	for (int i = 0; i < n; ++i) {
		cin >> arr[i];
	}
	int cnt = 0;
	int idx = 0;
	while (1) {
		if (idx == n) {
			idx = 0;
		}
		if (arr[idx] - cnt <= 0) {
			break;
		}
		else {
			idx++;
			cnt++;
		}
	}
	cout << idx + 1 << endl;
}
