#include <iostream>

using namespace std;

int main() {
	int n;
	cin >> n;
	long long mul = 1;
	for (int i = 2; i <= n; ++i) {
		mul *= i;
	}
	cout << mul;
	return 0;
}