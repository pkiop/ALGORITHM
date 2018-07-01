#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <cstring>
#include <string>

using namespace std;

int main(void) {
	int a, b, c;
	cin >> a >> b >> c;
	if (a > b) {
		int temp = a;
		a = b;
		b = temp;
	}
	if (a > c) {
		int temp = a;
		a = c;
		c = temp;
	}
	if (b > c) {
		int temp = b;
		b = c;
		c = temp;
	}

	string temp;
	cin >> temp;
	for (int i = 0; i < 3; ++i) {
		if (temp[i] == 'A') {
			cout << a << ' ';
		}
		if (temp[i] == 'B') {
			cout << b << ' ';
		}
		if (temp[i] == 'C') {
			cout << c << ' ';
		}
	}
	return 0;
}