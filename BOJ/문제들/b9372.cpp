#include <iostream>

using namespace std;

int main(void) {
	int t;
	cin >> t;
	int a, b;
	while (t--) {
		int n, m;
		cin >> n >> m;

		for (int i = 0; i < m; ++i) {
			cin >> a >> b;
		}
		cout << n - 1 << '\n';
	}
	return 0;
}
