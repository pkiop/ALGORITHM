#include <iostream>
#include <vector>
#include <algorithm>
#include <fstream>
#include <string>
#include <cstring>

#define GO

using namespace std;

/*

5 21
-3 2 -4 -1 -5

*/


int main(void) {

#ifdef GO
	freopen("input.txt", "r", stdin);
#endif

	int n;
	cin >> n;
	string ch;
	cin >> ch;
	vector<string> arr(n);
	for (int i = 0; i < n; ++i) {
		cin >> arr[i];
	}

	int len = ch.size();
	bool star = false;
	vector<char> front;
	vector<char> back;
	for (int i = 0; i < len; ++i) {
		if (ch[i] == '*') {
			star = true;
			continue;
		}
		if (!star) {
			front.push_back(ch[i]);
		}
		else {
			back.push_back(ch[i]);
		}
	}
	int fsize = front.size();
	int bsize = back.size();
	for (int i = 0; i < n; ++i) {

		bool flag = true;

		int slen = arr[i].size();
		int k;
		for (k = 0; k < fsize && k < slen; ++k) {
			if (front[k] != arr[i][k]) {
				flag = false;
				break;
			}
		}
		if (k != fsize) {
			flag = false;
		}
		int offset = bsize - 1;
		if (flag) {
			for (int j = slen - 1; offset != -1 && j>=fsize && j >= 0; j--) {
				if (back[offset] != arr[i][j]) {
					flag = false;
					break;
				}
				offset--;
			}
		}
		if (flag && offset == -1) {
			cout << "DA" << endl;
		}
		else {
			cout << "NE" << endl;
		}
	}

	return 0;
}