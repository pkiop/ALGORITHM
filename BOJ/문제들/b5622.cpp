#include <iostream>
#include <algorithm>
#include <string>
#include <list>

using namespace std;

int main(void) {
	string s;
	cin >> s;
	int n = 0;
	for (int i = 0; i < s.size(); ++i) {
		char c = s[i];
		if (c >= 'A' && c <= 'C') {
			n += 3;
		}

		if (c >= 'D' && c <= 'F') {
			n += 4;
		}

		if (c >= 'G' && c <= 'I') {
			n += 5;
		}
	
		if (c >= 'J' && c <= 'L') {
			n += 6;
		}
	
		if (c >= 'M' && c <= 'O') {
			n += 7;
		}
	
		if (c >= 'P' && c <= 'S') {
			n += 8;
		}
	
		if (c >= 'T' && c <= 'V') {
			n += 9;
		}
	
		if (c >= 'W' && c <= 'Z') {
			n += 10;
		}
	
	}
	cout << n;
	return 0;
}