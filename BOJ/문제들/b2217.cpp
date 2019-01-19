#include <iostream>
#include <vector>
#include <algorithm>

#define GO
using namespace std;

int arr[100001];

int main() {

#ifdef GO
	freopen("input.txt", "r", stdin);
#endif
	int n;
	cin >> n;
	for (int i = 0; i < n; ++i) {
		cin >> arr[i];
	}

	sort(arr, arr + n);

	int w, k;

	bool bkch = false;

	k = 1;
	w = 0;
	for (int i = n - 1; i >= 0; --i) {
		if (arr[i] * k >= w) {
			w = arr[i] * k;
		}
		k++;
	}


	cout << w << endl;
	return 0;


}