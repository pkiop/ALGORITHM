#include <iostream>
#include <string>

using namespace std;

string s;
int ans = 0;
void dfs(int idx, char beforechar, int beforeint) {
	if(idx == s.size()) {
		ans++;
		return;
	}

	if(s[idx] == 'c') {
		for(char c='a'; c<='z'; ++c) {
			if(beforechar == 'c') {
				continue;
			}
			dfs(idx+1, c, -1);
		}
	}
	else {
		for(int i=0;i<=9;++i) {
			if(i == beforeint) {
				continue;
			}
			dfs(idx+1, 'A', i);
		}
	}
}

int main(void) {
	cin >> s;
	dfs(0,'A',-1);
	cout << ans << endl;
}
