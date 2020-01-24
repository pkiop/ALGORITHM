#include <iostream>

using namespace std;

int main(void) {
	int a, b, c, d;
	cin >> a >> b >> c >> d;
	int k = (a-1) / b;
	cout << k * c * d;
	return 0;
}
