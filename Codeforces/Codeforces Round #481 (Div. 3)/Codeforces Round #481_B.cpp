#include <iostream>
#include <vector>
#include <algorithm>
#include <fstream>
#include <string>
#define GO

using namespace std;


/*

10
xxxxxxxxxx

*/

int main(void) {

#ifdef GO
	freopen("input.txt", "r", stdin);
#endif

	int n;
	string s;
	int cnt = 0;
	cin >> n >> s;
	for (int i = 0; i < n; ++i) {
		for (int j = i; j < i + 3; ++j) {
			if (s[j] != 'x') {
				break;
			}
			if (j == i + 2) {
				cnt++;
			}
		}
	}
	cout << cnt << endl;


	

}