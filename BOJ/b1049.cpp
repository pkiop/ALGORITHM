#include <iostream>
#include <algorithm>

using namespace std;

int main(void) {
	int num, n;
	cin >> num >> n;
	int sixmin=99999999, onemin=99999999;
	int six, one;
	for (int i = 0; i < n; ++i) {
		cin >> six >> one;
		sixmin = min(sixmin, min(six, one * 6));
		onemin = min(onemin, one);
	}
	int ans = num / 6 * sixmin;
	ans += (min(sixmin, onemin*(num % 6)));
	cout << ans << endl;
	return 0;
}