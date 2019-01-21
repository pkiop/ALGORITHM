#include <iostream>
#include <vector>
#include <algorithm>
#include <fstream>
#include <string>
#include <cstring>


using namespace std;

#define GO
vector<int> prime;

void findprime() {
	bool ok = false;
	for (int i = 2; i <= 10000; ++i) {
		ok = true;
		for (int j = 2; j<i; ++j) {
			if (i%j == 0) {
				ok = false;
				break;
			}
		}
		if (ok) {
			prime.push_back(i);
		}
	}
}

int main(void) {

#ifdef GO
	freopen("input.txt", "r", stdin);
#endif
	int t;
	cin >> t;
	int n;
	findprime();

	while (t--) {
		cin >> n;
		int ans1, ans2, subtract = 999999;
		for (int i = 0; prime[i] < n && i < prime.size(); ++i) {
			for (int j = 0; j <= i && j < prime.size(); ++j) {
				//cout << prime[i] << " + " << prime[j] << " = " << prime[i] + prime[j] << '\n';
				if (prime[i] + prime[j] == n && subtract > prime[i] - prime[j]) {
					subtract = prime[i] - prime[j];
					ans1 = prime[i];
					ans2 = prime[j];
				}
			}
		}
		cout << ans2 << ' ' << ans1 << '\n';
	}
	
	return 0;
}