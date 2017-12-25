#include <iostream>

using namespace std;

int d[1000001];

int f(int x) {
	if (x == 1) {
		return 0;
	}
	if (d[x] != 0) {
		return d[x];
	}
	d[x] = f(x - 1) + 1;
	if (x % 2 == 0) {
		int temp = f(x / 2) + 1;
		if (d[x] > temp) {
			d[x] = temp;
		}
	}
	if (x % 3 == 0) {
		int temp = f(x / 3) + 1;
		if (d[x] > temp) {
			d[x] = temp;
		}
	}
	return d[x];
}
int main() {
	int x;
	cin >> x;
	cout << f(x);
	return 0;
}