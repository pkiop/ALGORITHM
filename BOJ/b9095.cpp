#include <iostream>
#include <cstring>

using namespace std;

int d[100001];
int main() {
	int t;
	cin >> t;
	while (t--) {
		int k;
		cin >> k;
		memset(d, 0, sizeof(d));
		d[1] = 1;
		d[2] = 2;
		d[3] = 4;
		for (int i = 4; i <= k; ++i) {
			d[i] = d[i - 1] + d[i - 2] + d[i - 3];
		}
		cout << d[k] << '\n';
	}
	return 0;
}