#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
#include <cstring>
#include <map>
#include <set>
#include <string>

using namespace std;

int main(void) {
	int a, b;
	cin >> a >> b;
	string s;
	cin >> s;
	bool ans = true;
	for (int i = 0; i < a - b; ++i) {
		if (s[i] == '0' && (s[i + b] == '.' || s[i+b] == '1')) {
			s[i + b] = '1';
			ans = false;
			break;
		}
		if (s[i] == '1' && (s[i + b] == '.' || s[i + b] == '0')) {
			s[i + b] = '0';
			ans = false;
			break;
		}
		if (s[i] == '.' && s[i + b] == '1') {
			s[i] = '0';
			ans = false;
			break;
		}
		if (s[i] == '.' && s[i + b] == '0') {
			s[i] = '1';
			ans = false;
			break;
		}
	}
	for (int i = 0; i < a; ++i) {
		if (s[i] == '.') {
			s[i] = '0';
		}
	}


	if (!ans) {
		cout << s;
	}
	else {
		cout << "No";
	}
	return 0;
}