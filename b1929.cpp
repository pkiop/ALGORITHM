#include <iostream>

using namespace std;
bool prime[1001];
void find() {
	prime[0] = true;
	prime[1] = true;
	for (int i = 2; i < 1001; ++i) {
		for (int j = i * 2; j < 1001; j=j+i) {
			if (!prime[i]) {
				prime[j] = true;
			}
		}
	}
}
int d[101];
int main() {
	find();
	int a, b;
	cin >> a >> b;

	for (int i = a; i <= b; ++i) {
		if (!prime[i]) {
			cout << i << '\n';
		}
	}
	return 0;
}