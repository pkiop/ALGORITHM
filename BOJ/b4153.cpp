#include <iostream>
#include <algorithm>

using namespace std;

int main(void) {
	int a, b, c;
	while (cin >> a >> b >> c && a != 0 && b != 0 && c != 0) {
		int arr[3];
		arr[0] = a;
		arr[1] = b;
		arr[2] = c;
		sort(arr, arr + 3);
		if (arr[0] * arr[0] + arr[1] * arr[1] == arr[2] * arr[2]) {
			cout << "right" << '\n';
		}
		else {
			cout << "wrong" << '\n';
		}
	}
	return 0;
}