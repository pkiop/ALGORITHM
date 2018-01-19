#include <iostream>

using namespace std;

int main(void)
{
	int t;
	cin >> t;
	while (t--) {
		int a, b;
		cin >> a >> b;
		int temb = b;
		long long mul = 1;
		long long dev = 1;

		for (int i = 1; i <= b - a; ++i) {
			mul *= temb--;
			mul /= i;
		}

		cout << mul << endl;
	}

	return 0;

}
