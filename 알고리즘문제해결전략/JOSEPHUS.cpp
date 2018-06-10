#include <iostream>
#include <list>

using namespace std;

int main(void) {
	list<int> sv;
	int t;
	cin >> t;
	while (t--) {
		sv.clear();
		int n, k;
		cin >> n >> k;
		for (int i = 1; i <= n; ++i) {
			sv.push_back(i);
		}
		list<int>::iterator kill = sv.begin();
		while (n > 2) {
			kill = sv.erase(kill);
			if (kill == sv.end())
				kill = sv.begin();
			n--;
			for (int i = 0; i < k - 1; ++i) {
				++kill;
				if (kill == sv.end()) {
					kill = sv.begin();
				}
			}
		}

		cout << sv.front() << ' ' << sv.back() << endl;
	}
	system("pause");
	return 0;
}