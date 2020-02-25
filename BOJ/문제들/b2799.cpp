#include <iostream>
#include <string>
#include <vector>

using namespace std;

int ans[5];
int main(void) {
	int n, m;
	cin >> n >> m;
	vector<string> arr;
	string s;
	for(int i=0;i<n * 4 + n;++i) {
		cin >> s;
		if(s[1] == '#'){
			continue;
		}
		arr.push_back(s);
	}
	cin >> s;	
	for(int x=1;x<m * 4 + m + 1;x+=5) { 
		int cnt = 0;
		int star_cnt = 0;
		for(int y=0;y<arr.size();++y) {
			cnt++;
			if(arr[y][x] == '*') {
				star_cnt++;
			}
			if(cnt == 4) {
				//cout << star_cnt << ' ' << x << ' ' << y << '\n';
				ans[star_cnt]++;	
				star_cnt = 0;
				cnt = 0;
			}
		}
	}
	for(int i=0;i<5;++i) {
		cout << ans[i] << ' ';
	}
	return 0;
	
}
