#include <iostream>

using namespace std;
bool prime[1000001];
int pr[1000001];
int k = 0;
void find() {
	prime[0] = true;
	prime[1] = true;
	for (int i = 2; i < 1000001; ++i) {
		if (!prime[i]) {
			pr[k++] = i;
			for (int j = i * 2; j < 1000001; j = j + i) {
				prime[j] = true;
			}
		}
	}
}

int main() {
	find();
	int n;
	cin >> n;
	if (n == 1) {
		cout << 1;
		return 0;
	}
	
	for (int i = 0; i < n; ++i) {
		while (n%pr[i] == 0) {
			cout << pr[i] << '\n';
			n /= pr[i];
		}
	}
	
	return 0;
}