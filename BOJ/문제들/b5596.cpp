#include <iostream>

using namespace std;

int main(void) {
	int a, b, c, d;
	int aa, bb, cc, dd;
	cin >> a >> b >> c >> d >> aa >> bb >> cc >> dd;
	int temp1, temp2;
	temp1 = a + b + c + d;
	temp2 = aa + bb + cc + dd;
	if (temp1 > temp2) {
		cout << temp1;
	}
	else {
		cout << temp2;

	}
	return 0;
}