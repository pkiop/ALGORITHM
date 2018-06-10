#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;

double cache2[1001][1001];
int n, m;

double climb(int days, int climbed) {
	// m일 까지 왔을 떄 올라온 높이가 n보다 큰가?
	//cout << days << " m " <<m <<endl;
	if (days == m) return climbed >= n ? 1.0 : 0.0;

	double& ret = cache2[days][climbed];

	if (ret != -1.0) return ret;
	//이 아래의 return 문이 2^n개의 경우의 수를 다 만들어 준다. 
	return ret = 0.25*climb(days + 1, climbed + 1) + 0.75*climb(days + 1, climbed + 2);
}

int main(void)
{
	int t;
	cin >> t;
	while (t--) {
		for (int i = 0; i < 1001; ++i) {
			for (int j = 0; j < 1001; ++j) {
				cache2[i][j] = -1.0;
			}
		}
		cin >> n >> m;
		cout.precision(8);
		cout << fixed;
		cout << climb(0, 0) << endl;
	}
	return 0;
}