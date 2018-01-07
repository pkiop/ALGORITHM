#include <iostream>
#include <algorithm>
#include <string>
#include <vector>

using namespace std;

struct ans {
	int n;
	string name;
	bool operator < (const ans& v) {
		if (n < v.n) {
			return true;
		}
		else if (n == v.n) {
			return name < v.name;
		}
		return false;
	}
};
int main() {
	int n;
	cin >> n;
	struct ans k[1001];
	for (int i = 0; i < n; ++i) {
		cin >> k[i].n >> k[i].name;
	}
	sort(k, k + n); 
	for (int i = 0; i < n; ++i) {
		cout << k[i].n << ' ' << k[i].name << '\n';
	}
	return 0;
}