#include <iostream>
#include <algorithm>
#include <cstring>
#include <limits.h>
#include <stack>

using namespace std;

int table[1001][1001];
int cache[1001][1001];
int dx[] = { 1,0,1 };
int dy[] = { 0,1,1 };
int n, m;
int go(int x, int y) {
	//cout << "root : " << table[x][y] << endl;
	if (cache[x][y] != -1) {
		return cache[x][y];
	}

	cache[x][y] = table[x][y];
	int& ret = cache[x][y];
	for (int k = 0; k < 3; ++k) {
		int nx = x + dx[k];
		int ny = y + dy[k];
		if (0 <= nx && nx < n && 0 <= ny && ny < m) {
			ret = max(ret,go(nx, ny)+table[x][y]);	
			
		}
	}
	return ret;
}
int main(void) {
	memset(cache, -1, sizeof(cache));
	cin >> n >> m;
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < m; ++j) {
			cin >> table[i][j];
		}
	}
	
	cout << go(0, 0);
	return 0;
}