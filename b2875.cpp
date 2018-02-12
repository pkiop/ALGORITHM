#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
	int n, m, k;
	cin >> n >> m >> k;
	bool mant = true;
	int make_team,left,ans;
	if (n > m * 2) {
		mant = false;
		make_team = m;
		left = n - m * 2;
	}
	else {
		make_team = n / 2;
		left = m - n / 2;
	}
	//cout << "left = " << left << endl;
	
	if (left >= k) {
		ans = make_team;
	}
	else { // destroy team
		k -= left;
		ans = make_team - (k-1)/3-1;
	}
	cout << ans;


	
	return 0;
}