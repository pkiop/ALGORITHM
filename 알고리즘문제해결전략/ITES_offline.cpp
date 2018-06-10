#include <iostream>
#include <limits>
#include <algorithm>

using namespace std;

struct RNG {
	unsigned seed;
	RNG() : seed(1983){}
	unsigned next() {
		unsigned ret = seed;
		seed = ((seed * 214013u) + 2531011u);
		return ret % 10000 + 1;
	}
};

int n, k;
int go() {
	
	int ret = 0;
	for (int i = 0; i <= n; ++i) {
		RNG num;
		for (int k = 0; k < i; ++k) {
			num.next();
		}
		int sum = 0;
		for (int j = i; j <= n; ++j) {
			int temp = num.next();
			sum += temp;
			//cout << sum << endl;
			
			if (sum == k) {
				ret += 1;
			}
			if (sum >= k) {
				break;
			}
		}
	}
	return ret;
}
int main(void)
{
	int t;
	cin >> t;

	while (t--) {
		cin >> k;
		cin >> n;
		cout << go() << endl;
	}
}