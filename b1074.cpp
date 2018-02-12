#include <iostream>

using namespace std;

int power2(int k) {
	return (1 << k); //2^k by shift operator
}
int go(int n, int x, int y) {
	if (n == 1) { // repeat devide, and n==1 => finish
		return 2 * x + y;
	}
	else {
		if (x < power2(n - 1)) {
			if (y < power2(n - 1)) {
				return go(n - 1, x, y);
			}
			else {
				return go(n - 1, x, y - power2(n - 1)) + power2(2 * n - 2);
			}
		}
		else {
			if (y < power2(n - 1)) {
				return go(n - 1, x - power2(n - 1), y) + power2(2 * n - 2) * 2;
			}
			else {
				return go(n - 1, x - power2(n - 1), y - power2(n - 1)) + power2(2 * n - 2) * 3;
			}
		}
	}
}
int main(void)
{
	int n, r, c;
	while (cin >> n >> r >> c) {
		cout << go(n, r, c) << '\n';
	}
	return 0;
}