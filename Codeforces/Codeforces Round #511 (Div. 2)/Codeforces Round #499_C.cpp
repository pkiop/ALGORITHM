#include <iostream>
#include <vector>
#include <algorithm>
#include <fstream>
#include <string>
#include <cstring>
#define GO
#define DEBUG

using namespace std;

/*

6
2
4 6 3 3 5 6
2 6 3 6 5 3

*/
#define MAXV 1000000000
int a[1001];
int b[1001];

int main(void) {

#ifdef GO
	freopen("input.txt", "r", stdin);
#endif
	int n, m;
	cin >> n >> m;
	// -1이 나오는 경우는 takeoff나 landing coeff == 1 인게 하나라도 있을때 
	for (int i = 0; i < n; ++i) {
		cin >> a[i];
		if (a[i] == 1) {
			cout << -1 << endl;
			return 0;
		}
	}
	for (int i = 0; i < n; ++i) {
		cin >> b[i];
		if (b[i] == 1) {
			cout << -1 << endl;
			return 0;
		}
	}

	double left = 1, right = MAXV;

	while (left < right) {
		double mid = (left + right) / 2;
		bool ok = true;
		double first = double(m) + mid;
		double now = first - first / a[0];
		for (int i = 1; i < n; ++i) {
			if (now < m) {
				ok = false;
				break;
			}
			now = now - now / b[i];
			if (now < m) {
				ok = false;
				break;
			}
			now = now - now / a[i];
		}
		if (ok) {
			now = now - now / b[0];
			if (now < m) {
				ok = false;
			}
		}

		if (!ok) {
			left = mid + 0.000001;
		}
		else {
			right = mid - 0.000001;
		}
	}
	

	cout.precision(10);
	cout << left << endl;
	return 0;
}