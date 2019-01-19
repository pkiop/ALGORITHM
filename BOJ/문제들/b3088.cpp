#include <iostream>

using namespace std;

int tb2[300001][3];
bool breaknum[1000001];
int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int n;
	cin >> n;
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < 3; ++j) {
			cin >> tb2[i][j];
		}
	}
	int anscnt = 0;
	for (int i = 0; i < n; ++i) {
		bool breakon = true;
		for (int j = 0; j < 3; ++j) {
			if (breaknum[tb2[i][j]]) {
				breakon = false;			
			}
			else {
				breaknum[tb2[i][j]] = true;
			}
		}
		if (breakon) {
			anscnt++;
		}
	}
	cout << anscnt << endl;
	return 0;
}