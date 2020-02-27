#include <iostream>
#include <vector>
#include <string>

using namespace std;

int main(void) {
	int n;
	cin >> n;
	string s;
	vector<string> arr;
	for(int i=0;i<n;++i) {
		cin >> s;
		arr.push_back(s);
	}

	//garo
	int garo_cnt = 0;
	for(int i=0;i<n;++i) {
		int cnt = 0;
		for(int j=0;j<n;++j) {
			if(arr[i][j] == '.') {
				cnt++;
			}
			else {
				cnt = 0;
			}
			if(cnt == 2) {
				garo_cnt++;
			}
		}
	}
	int sero_cnt = 0;
	for(int i=0;i<n;++i) {
		int cnt = 0;
		for(int j=0;j<n;++j) {
			if(arr[j][i] == '.') {
				cnt++;
			}
			else {
				cnt = 0;
			}
			if(cnt == 2) {
				sero_cnt++;
			}
		}
	}
	cout << garo_cnt << ' ' << sero_cnt << endl;
	return 0;

}
