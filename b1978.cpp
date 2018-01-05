#include <iostream>

using namespace std;
bool prime[101];
void find() {
	for (int i = 2; i < 101; ++i) {
		for (int j = i * 2; j < 101; j=j+2) {
			if (!prime[i]) {
				prime[j] = true;
			}
		}
	}
}
int d[1001];
int main() {
	int n; cin >> n;
	for (int i = 0; i < n; ++i) {
		cin >> d[i];
	}
	int ans = 0;
	for (int i = 0; i < n; ++i) {
		if (!prime[d[i]])
			ans += 1;
	}
	cout << ans;
	return 0;
}