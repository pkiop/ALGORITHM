#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

typedef long long ll;
int main(void) {
	int n, m;
	cin >> n >> m;
	int now = 0;
	int temp;
	for (int i = 0; i < n; ++i) {
		cin >> temp;
		cout << (now + temp) / m << ' ';
		now = (now + temp) % m;
	}
	return 0;
}