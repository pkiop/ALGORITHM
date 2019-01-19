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
	string a, b;
	cin >> a >> b;
	int alen = a.size();
	int blen = b.size();

	int lappend = 0;
	int rappend = blen - alen;
	int tans = 0;
	int minans = 99999;
	while (lappend != rappend + 1) {
		tans = 0;
		for (int i = 0; i < alen; ++i) {
			if (a[i] != b[i + lappend]) {
				tans++;
			}
		}
		minans = min(minans, tans);

		lappend++;
	}

	cout << minans << endl;
	return 0;


	return 0;
}