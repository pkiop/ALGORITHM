#include <iostream>
#include <algorithm>

using namespace std;

int arr[100001];

int main(void) {
	int n;
	cin >> n;
	for (int i = 0; i < 2*n; ++i) {
		cin >> arr[i];
	}
	int idx = 0;
	int findidx = 0;
	int cnt = 0;
	while (1) {
		if (idx == 2 * n) {
			break;
		}
		if (arr[idx] == arr[idx + 1]) {
			idx += 2;
		}
		else {
			for (int i = idx + 2; i < 2 * n; ++i) {
				if (arr[idx] == arr[i]) {
					findidx = i;
				}
			}
			while (findidx != idx + 1) {
				swap(arr[findidx], arr[findidx - 1]);
				findidx--;
				cnt++;
			}
		}
	}
	cout << cnt << endl;
	return 0;
}
