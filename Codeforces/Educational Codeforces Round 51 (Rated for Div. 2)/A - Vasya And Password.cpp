#include <iostream>
#include <vector>
#include <algorithm>
#include <fstream>
#include <string>
#include <cstring>
#define GO
#define DEBUG

using namespace std;

/*

3
afd
142
TRE
*/


int main(void) {

#ifdef GO
	freopen("input.txt", "r", stdin);
#endif

	int n;
	cin >> n;
	while (n--) {
		string s;
		cin >> s;
		int len = s.size();
		int U = 0; //uppercase
		int L = 0; //lowercase
		int N = 0; //number
		vector<int> Uidxs, Lidxs, Nidxs;
		for (int i = 0; i < len; ++i) {
			char c = s[i];

			if (c >= 'a' && c <= 'z') {
				L++;
				Lidxs.push_back(i);
			}
			if (c >= 'A' && c <= 'Z') {
				U++;
				Uidxs.push_back(i);
			}
			if (c >= '0' && c <= '9') {
				N++;
				Nidxs.push_back(i);
			}
		}
		int Li, Ui, Ni;
		Li = Ui = Ni = 0;
		if (U == 0) {
			if (L > 1) {
				s[Lidxs[Li++]] = 'U';
			}
			else {
				s[Nidxs[Ni++]] = 'U';
			}
		}
		if (L == 0) {
			if (U > 1) {
				s[Uidxs[Ui++]] = 'a';
			}
			else {
				s[Nidxs[Ni++]] = 'a';
			}
		}

		if (N == 0) {
			if (U > 1) {
				s[Uidxs[Ui++]] = '0';
			}
			else {
				s[Lidxs[Li++]] = '0';
			}
		}
		cout << s << '\n';
	}

	return 0;
}