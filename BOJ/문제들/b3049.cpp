#include <iostream>

using namespace std;

int main(void) {
	int n;
	cin >> n;
	long long ans = 1;
	for(int i=n;i>=n-3;--i) {
		ans *= i;
	}
	cout << ans / 24;
	return 0;
}
