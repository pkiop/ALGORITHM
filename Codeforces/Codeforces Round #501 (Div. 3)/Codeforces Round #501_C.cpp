#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int main(void) {
	int n, m;
	cin >> n >> m;
	vector<int> dif(n);
	int a, b;
	long long sum = 0;
	for (int i = 0; i < n; ++i) {
		cin >> a >> b;
		dif[i] = a - b;
		sum += a;
	}
	sort(dif.begin(), dif.end());
	reverse(dif.begin(), dif.end());
	int iter = 0;
	while (sum > m && iter != n) {
		sum -= dif[iter++];
	}
	if (iter == n && sum > m) {
		cout << -1;
	}
	else {
		cout << iter << endl;
	}

	return 0;
}