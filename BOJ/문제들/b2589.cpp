#include <iostream>
#include <map>
#include <vector>
#include <algorithm>
#include <queue>
#include <string>
#include <cstring>

using namespace std;

int visited[51][51];
string arr[51];
int dx[] = { 1,-1,0,0 };
int dy[] = { 0,0,1,-1 };
int n, m;
int maxans = 0;
void bfs(int x,int y) {
	visited[x][y] = 0;
	queue<pair<int, int> > q;
	q.push(make_pair(x, y));
	while (!q.empty()) {
		int mx = q.front().first;
		int my = q.front().second;
		q.pop();
		for (int k = 0; k < 4; ++k) {
			int nx = mx + dx[k];
			int ny = my + dy[k];
			int dist = visited[mx][my];
			if (0 <= nx && nx < n && 0 <= ny && ny < m) {
				if (arr[nx][ny] == 'L' && visited[nx][ny] == -1) {
					q.push(make_pair(nx, ny));
					visited[nx][ny] = dist + 1;
					maxans = max(maxans, visited[nx][ny]);
				}
			}
		}
	}

}

int main(void) {
	cin >> n >> m;
	for (int i = 0; i < n; ++i) {
		cin >> arr[i];
	}
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < m; ++j) {
			memset(visited, -1, sizeof(visited));

			if (arr[i][j] == 'L' && visited[i][j] == -1) {
				bfs(i, j);
			}
		}
	}

	cout << maxans << '\n';
	return 0;
}