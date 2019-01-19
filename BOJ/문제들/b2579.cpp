#include <iostream>

using namespace std;

#define MAX(a,b) ((a)>(b)?(a):(b))

int a[301];
int d[301][2];
int main() {
	int n;
	cin >> n;
	for (int i = 0; i < n; ++i) {
		cin >> a[i];
	}
	d[0][0] = a[0];
	d[0][1] = a[0];
	d[1][0] = a[0] + a[1];
	d[1][1] = a[1];
	for (int i = 2; i < n; ++i) {
		d[i][0] = d[i - 1][1] + a[i];
		d[i][1] = MAX(d[i - 2][0], d[i - 2][1]) + a[i];
	}
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < 2; ++j) {
			cout << d[i][j] << ' ';
		}
		cout << '\n';
	}
	cout << boolalpha;
	cout << 1;
	cout << MAX(d[n - 1][0], d[n - 1][1]);
	return 0;
}