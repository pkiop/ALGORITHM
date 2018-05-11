#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

struct g {
	string name;
	int kr;
	int en;
	int me;
	bool operator < (const g& u) {
		if (kr > u.kr)
			return true;
		else if (kr == u.kr && en < u.en) {
			return true;
		}
		else if (kr == u.kr && en == u.en && me > u.me) {
			return true;
		}
		else if (kr == u.kr && en == u.en && me == u.me && name < u.name)
			return true;
		else
			return false;
	}
};



int main() {
	int n;
	cin >> n;
	g gg[101];
	for (int i = 0; i < n; ++i) {
		cin >> gg[i].name >> gg[i].kr >> gg[i].en >> gg[i].me;
	}
	sort(gg, gg + n);
	for (int i = 0; i < n; ++i) {
		cout << gg[i].name << '\n';
	}
	return 0;
}