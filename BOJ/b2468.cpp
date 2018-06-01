#include <vector>
#include <stack>
#include <iostream>
#include <algorithm>
#include <cstring>
using namespace std;

int arr[101][101];
bool visited[101][101];
int dx[] = { 1,-1,0,0 };
int dy[] = { 0,0,1,-1 };
int h;
int n;
void dfs(int x, int y) {
	visited[x][y] = true;
	for (int k = 0; k < 4; ++k) {
		int nx = x + dx[k];
		int ny = y + dy[k];
		if (0 <= nx && nx < n && 0 <= ny && ny < n) {
			if (!visited[nx][ny] && arr[nx][ny] >= h) {
				dfs(nx, ny);
			}
		}
	}
}
int main(void) {
	cin >> n;
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < n; ++j) {
			cin >> arr[i][j];
		}
	}
	int cnt;
	int maxcnt = 0;
	for (h = 1; h <= 100; ++h) {
		cnt = 0;
		memset(visited, false, sizeof(visited));
		for (int i = 0; i < n; ++i) {
			for (int j = 0; j < n; ++j) {
				if (!visited[i][j] && arr[i][j] >= h) {
					dfs(i, j);
					cnt++;
				}
			}
		}
		maxcnt = max(maxcnt, cnt);
	}
	cout << maxcnt << '\n';
	return 0;
}