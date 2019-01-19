#include <iostream>
#include <string>
using namespace std;

int main(void)
{
	int n;
	cin >> n;
	string s;
	getline(cin, s);//쓰레기
	
	for (int i = 0; i < n; ++i) {
		getline(cin, s);
		//cout << s << endl;
		int len = s.size();
		int len2 = len / 2;
		bool yes = true;
		int cha = 'a' - 'A';
		for (int i = 0; i < len2; ++i) {
			if (s[i] != s[len - i - 1]) {
				if (s[i] + cha == int(s[len - i - 1]) || int(s[i]) == s[len - i - 1] + cha) {

				}
				else {
					cout << "No" << endl;
					yes = false;
					break;
				}
			}
		}
		if (yes) {
			cout << "Yes" << endl;
		}
	}
	return 0;
}