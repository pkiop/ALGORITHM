#include <iostream>
#include <cstring>
using namespace std;

#define MAX(a,b) (((a)>(b))?(a):(b))
int score[100001][2];
int d[100001][3];
int main() {
	int t;
	cin >> t;
	while (t--) {
		int k;
		cin >> k;
		memset(score, 0, sizeof(score));
		memset(d, 0, sizeof(d));
		for (int i = 0; i <= 1; ++i) {
			for (int j = 0; j < k; ++j) {
				cin >> score[j][i];
			}
		}

		d[1][0] = 0;
		d[1][1] = score[0][0];
		d[1][2] = score[0][1];

		for (int i = 2; i <= k; ++i) {
			d[i][0] = MAX(d[i - 1][0], MAX(d[i - 1][1], d[i - 1][2]));
			d[i][1] = MAX(d[i - 1][2], d[i - 1][0]) + score[i-1][0];
			d[i][2] = MAX(d[i - 1][1], d[i - 1][0]) + score[i-1][1];
		}
		cout << MAX(d[k][0], MAX(d[k][1], d[k][2])) << '\n';
		
	}
	return 0;
}