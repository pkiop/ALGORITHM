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

5 21
-3 2 -4 -1 -5

*/


int main(void) {

#ifdef GO
	freopen("input.txt", "r", stdin);
#endif

	int n, w;
	cin >> n >> w;
	int x;
	int sum = 0;
	int minv = 99999, maxv = -99999;
	for (int i = 0; i < n; ++i) {
		cin >> x;
		sum += x;
		minv = min(sum, minv);
		maxv = max(sum, maxv);
	}

#ifdef DEBUG
	cout << "minv : " << minv << " maxv : " << maxv << endl;
#endif
	int minstart = (minv < 0 ? minv : 0);
	if (abs(minv) > w) {
		cout << 0 << endl;
		return 0;
	}
	int maxbound = maxv - minstart;
	if (w - abs(maxbound) < 0) {
		cout << 0 << endl;
		return 0;
	}
	cout << min(w - maxbound + 1,w -abs(minstart) + 1) << endl;
	
	return 0;


}