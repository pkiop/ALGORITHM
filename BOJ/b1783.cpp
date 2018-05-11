#include <iostream>
#include <algorithm>

using namespace std;

int main(void)
{
	int n, m,ans;
	cin >> n >> m;
	
	if (n >= 3 && m >= 7) {
		ans = m - 2;
	}
	else if (n >= 3 && m < 7) {
		if (m >= 4)
			ans = 4;
		else
			ans = m;
	}
	else if (n == 2) {
		ans = min(3,1 + (m-1) / 2);
	}
	else
		ans = 1;
	cout << ans;
}