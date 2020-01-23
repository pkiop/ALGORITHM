#include <iostream>
#include <string>

using namespace std;

int main(void) {
	string s;
	cin >> s;
	int line = 2;
	while(s != "Was") {
		int idx = 0;
		while(idx < s.size()) {
			//cout << idx << endl;
			cout << s[idx];
			idx += line;
			
		}
		line++;
		cout << endl;
		cin >> s;
	}
}
