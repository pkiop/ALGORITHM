#include <iostream>
#include <string>
#include <algorithm>
using namespace std;


int main(void) {
	string s;
	cin >> s;
	char now_char = 'A';
	int ans = 0;
	for(int i=0;i<s.size();++i) {
		int now_num = abs(now_char - s[i]);
		if(now_num < 13) {
			now_char = s[i];
			ans += now_num;
		}
		else {
			now_char = s[i];
			now_num = 26 - now_num;
			ans += now_num;
		}
	}
	cout << ans << endl;
}
