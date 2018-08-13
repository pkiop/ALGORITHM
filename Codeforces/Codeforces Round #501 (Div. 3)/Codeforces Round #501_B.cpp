#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int cnt_s[27];
int cnt_t[27];

int main(void) {
	int n;
	cin >> n;
	string s, t;
	cin >> s >> t;
	int len = s.size();
	vector<int> ans;
	for (int i = 0; i < len; ++i) {
		cnt_s[s[i] - 'a']++;
		cnt_t[t[i] - 'a']++;
	}
	for (int i = 0; i < 27; ++i) {
		if (cnt_s[i] != cnt_t[i]) {
			cout << -1;
			return 0;
		}
	}
	for (int i = 0; i < len; ++i) {
		if (s[i] == t[i]) {
			continue;
		}
		for (int j = i+1; j < len; ++j) {
			if (t[i] == s[j]) {
				for (int k = j-1; k >= i; --k) {
					ans.push_back(k+1);
					swap(s[k], s[k+1]);
				}
				break;
			}
		}
	}
	//cout << s << endl;
	len = ans.size();
	cout << len << endl;
	for (int i = 0; i < len; ++i) {
		cout << ans[i] << ' ';
	}
	return 0;

}