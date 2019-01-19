#include <iostream>
#include <cstring>

using namespace std;
int che[100001];
int main() {
	int t;
	cin >> t;
	while (t--) {
		memset(che, 0, sizeof(che));
		int n;
		cin >> n;
		for (int i = 2; i*i <= n; ++i) {
			while (n%i == 0) {
				che[i]++;
				n /= i;
			}
		}
		if (n > 1)
			che[n]++;

		for (int i = 0; i < 100001; ++i) {
			if (che[i] != 0) {
				cout << i << ' ' << che[i] << '\n';
			}
		}
	}

	return 0;
}