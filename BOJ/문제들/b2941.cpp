#include <iostream>
#include <algorithm>
#include <vector>
#include <cstring>
#include <string>

using namespace std;

int main(void)
{
	string s;
	cin >> s;
	int len = s.size();
	int ans = 0;
	for (int i = 0; i < len; ++i) {
		if (s[i] == 'c' && i != len-1) {
			if (s[i + 1] == '=' || s[i + 1] == '-') {
				ans++;
				i += 1;
				continue;
			}
		}
		if (s[i] == 'd' && i!=len-1) {
			if (s[i + 1] == 'z' && i+1 != len-1) {
				if (s[i + 2] == '=') {
					ans++;
					i += 2;
					continue;
				}
				else {
					ans+=2;
					i += 1;
					continue;
				}
			}
			if (s[i + 1] == '-' && i + 1 != len - 1) {
				ans++;
				i += 1;
				continue;
			}
		}
		if ((s[i] == 'l' || s[i] == 'n')&& i != len - 1) {
			if (s[i + 1] == 'j') {
				ans++;
				i += 1;
				continue;
			}
		}
		if (s[i] == 's' && i != len - 1) {
			if (s[i + 1] == '=') {
				ans++;
				i += 1;
				continue;
			}
		}
		if (s[i] == 'z' && i != len - 1) {
			if (s[i + 1] == '=') {
				ans++;
				i += 1;
				continue;
			}
		}
		ans++;
	}
	cout << ans;

	return 0;
}