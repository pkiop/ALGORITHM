#include <iostream>

using namespace std;

int main(void) {
	int n;
	cin >> n;
	while(n--) {
		int a, b;
		cin >> a >> b;
		//12
		if(a < 12 || b < 4) {
			cout << -1 << endl;
		}
		else {
			cout << 11 * b + 4 << endl;
		}
	}

}
