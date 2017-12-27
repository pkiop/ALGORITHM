#include <iostream>

using namespace std;

int input[1001];
int d[1001];

int main() {
	int n;
	cin >> n;
	for (int i = 1; i <= n; ++i) {
		cin >> input[i];
	}

	for (int i = 1; i <= n; ++i) {
		d[i] = 1;
		for (int j = 1; j < i; ++j) {
			if ((input[i] > input[i - j]) && (d[i] <= d[i - j])) {
				d[i] = d[i - j] + 1;
			}
		}
	}
	int find_max = 0;
	for (int i = 1; i <= n; ++i)
		if (find_max < d[i])
			find_max = d[i];
	cout << find_max;
	return 0;
}