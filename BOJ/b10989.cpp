#include <iostream>
#include <algorithm>
#include <vector>
#include <cstring>
using namespace std;
int a[10001] = { 0, };

int main() {
	memset(a, 0, sizeof(a));
	int n;
	cin >> n;
	int nn = n;
	while (n--) {
		int k;
		cin >> k;
		a[k]++;
	}

	for (int i = 1; i < 10001; ++i) {
		int kk = a[i];
		for (int j = 0; j < kk; ++j) {
			printf("%d\n", i);
		}

	}
	return 0;
}