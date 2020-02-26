#include <iostream>
#include <string>
#include <vector>

using namespace std;

int dx[] = {0, 0, 1, -1};
int dy[] = {1, -1, 0, 0};


vector<string> arr;
int main(void) {
	int n, m;
	cin >> n >> m;
	string s;
	for(int i=0;i<n;++i) {
		cin >> s;
		arr.push_back(s);
	}

	for(int y=0;y<n;++y) {
		for(int x=0;x<m;++x) {
			if(arr[y][x] == '.') {
				int cnt = 0;
				for(int k=0;k<4;++k) {
					int nx = x + dx[k];
					int ny = y + dy[k];
					if(0 > nx || nx >= m || 0 > ny || ny >= n) {
						continue;
					}
					if(arr[ny][nx] == '.') {
						cnt++;
					}
				}
				if(cnt <= 1) {
					cout << 1;
					return 0;
				}
			}
		}
	}
	cout << 0;
	return 0;

}
