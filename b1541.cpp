#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main(void)
{
	string s;
	cin >> s;
	vector<int> sum;
	vector<int> sign;
	int cur = 0;
	sign.push_back(1);
	int st_len = s.length();
	for (int i = 0; i < st_len; ++i)
	{
		if (s[i] == '+' || s[i] == '-') {
			if (s[i] == '+')
				sign.push_back(1);
			else
				sign.push_back(-1);
			sum.push_back(cur);
			cur = 0;
		}
		else {
			cur = cur * 10 + (s[i] - '0');
		}
	}
	sum.push_back(cur);
	int ans = 0;
	bool minus = false;
	for (int i = 0; i < sum.size(); ++i) {
		if (sign[i] == -1)
			minus = true;
		if (minus) {
			ans -= num[i];
		else
			ans += num[i];
		}
	}
	cout << ans << '\n';
	return 0;
}