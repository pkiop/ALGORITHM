#include <iostream>
#include <vector>
#include <algorithm>
#include <fstream>
#include <string>
#include <cstring>

#define GO

using namespace std;

int flr[10001];
int pos[10001];

int main(void) {

#ifdef GO
	freopen("input.txt", "r", stdin);
#endif
	int t;
	cin >> t;
	
	int width = 0;
	int wid = 1;
	int hei = 1;
	int num = 1;
	while (num != 10001) {
		width++;
		wid = 1;
		while(wid <= width){
			if (num == 10001) {
				break;
			}
			flr[num] = hei;
			pos[num++] = wid++;
		}
		hei++;
	}
	for (int T = 1; T <= t; ++T) {
		int a, b;
		cin >> a >> b;
		cout << '#' << T << ' ';
		if (a > b) {
			swap(a, b);
		}
		if (pos[a] > pos[b]) {
			cout << abs(pos[b] - pos[a]) + flr[b] - flr[a] << '\n';
		}
		else {
			cout << max(abs(pos[b] - pos[a]), flr[b] - flr[a]) << '\n';
		}

	}


	return 0;
}