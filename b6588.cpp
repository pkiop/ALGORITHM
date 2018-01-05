#include <iostream>

using namespace std;
bool prime[1000001];
int pr[1000001];
void find() {
	prime[0] = true;
	prime[1] = true;
	int k = 0;
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
	int a=1;
	bool ch = false;
	while (a!=0) {
		cin >> a;
		for (int i = 0; pr[i] < a - 1; ++i) {
			if (!prime[a - pr[i]]) {
				cout << a << " = " << pr[i] << " + " << a - pr[i] << '\n';
				break;
			}
		}
	}
	

	
	return 0;
}