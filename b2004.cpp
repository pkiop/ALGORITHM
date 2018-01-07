#include <iostream>

using namespace std;

typedef long long l;

int main() {
	l a, b,two=0,fiv=0;
	cin >> b >> a;
	for (l i = 2; i <= b; i *= 2) {
		two += b / i;
	}
	for (l i = 5; i <= b; i *= 5) {
		fiv += b / i;
	}
	for (l i = 2; i <= a; i *= 2) {
		two -= a / i;
	}
	for (l i = 2; i <= b-a; i *= 2) {
		two -= (b-a) / i;
	}
	for (l i = 5; i <= a; i *= 5) {
		fiv -= a / i;
	}
	for (l i = 5; i <= b-a; i *= 5) {
		fiv -= (b-a) / i;
	}
	cout << (two > fiv ? fiv : two);
	return 0;
}