#include <iostream>
#include <string>
#include <algorithm>
using namespace std;


int main(void) {
	int n;
	string s;
	cin >> n >> s;
	int bonus = 0;
	int ans = 0;
	for(int i=1;i<=n;++i) {
		if(s[i-1] == 'O') {
			ans = ans + bonus + i;
			bonus++;
		}
		else {
			bonus = 0;
		}
	}
	cout << ans << endl;
	return 0;
} 
