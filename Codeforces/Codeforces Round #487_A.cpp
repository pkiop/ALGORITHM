#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
#include <cstring>
#include <map>
#include <set>
#include <string>

using namespace std;

bool abc[] = { false,false,false };
int main(void) {
	string s;
	cin >> s;
	int len = s.size();
	bool ans = false;
	bool contig = false;
	for (int i = 0; i < len; ++i) {
		if (s[i] == 'A')
			abc[0] = true;
		if (s[i] == 'B')
			abc[1] = true;
		if (s[i] == 'C')
			abc[2] = true;
		if (s[i] == '.')
			for (int j = 0; j < 3; ++j)
				abc[j] = false;
		bool state = false;
		for (int k = 0; k < 3; ++k) {
			if (abc[k] == false) {
				state = true;
			}
		}
		if (state == false) {
			ans = true;
			break;
		}
	}
	if (ans) {
		cout << "Yes" << endl;
	}
	else {
		cout << "No" << endl;
	}
	return 0;
}