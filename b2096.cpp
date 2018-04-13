#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <cstring>


using namespace std;

int n;
int tb[3];
int che[3][3];
int mche[3][3];

int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	for (int i = 0; i < 3; ++i) {
		che[1][i] = -1;
		mche[1][i] = INT32_MAX;
	}
	int n;
	cin >> n;
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < 3; ++j) {
			cin >> tb[j];
		}
		
		if (i == 0) {
			for (int k = 0;  k < 3; ++k) {
				che[i][k] = tb[k];
				mche[i][k] = tb[k];
			}
		}
		else {
			for (int k = 0; k < 2; ++k) {
				che[1][0] = max(che[1][0], che[0][k] + tb[0]);
				mche[1][0] = min(mche[1][0],mche[0][k] + tb[0]);
			}
			for (int k = 0; k < 3; ++k) {
				che[1][1] = max(che[1][1], che[0][k] + tb[1]);
				mche[1][1] = min(mche[1][1], mche[0][k] + tb[1]);
			}
			for (int k = 1; k < 3; ++k) {
				che[1][2] = max(che[1][2], che[0][k] + tb[2]);
				mche[1][2] = min(mche[1][2], mche[0][k] + tb[2]);
			}
			for (int k = 0; k < 3; ++k) {
				che[0][k] = che[1][k];
				mche[0][k] = mche[1][k];
				che[1][k] = -1;
				mche[1][k] = INT32_MAX;
			}
		}
	}
	int ans = 0;
	for (int i = 0; i < 3; ++i) {
		ans = max(ans, che[0][i]);
	}
	cout << ans << ' ';
	ans = INT32_MAX;
	for (int i = 0; i < 3; ++i) {
		ans = min(ans, mche[0][i]);
	}
	cout << ans << endl;

	return 0;
}
