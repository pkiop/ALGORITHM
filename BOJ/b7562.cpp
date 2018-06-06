#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <cstring>
#include <string>
#include <map>

using namespace std;

int dx[8] = { 1,2,2,1,-1,-2,-2,-1 };
int dy[8] = { 2,1,-1,-2,-2,-1,1,2 };
int dist[301][301];

int n;

void bfs(int x, int y) {
	dist[x][y] = 0;
	queue<pair<int, int> > q;
	q.push(make_pair(x, y));
	while (!q.empty()) {
		int mx = q.front().first;
		int my = q.front().second;
		q.pop();
		for (int k = 0; k < 8; ++k) {
			int nx = mx + dx[k];
			int ny = my + dy[k];
			if (0 <= nx && nx < n && 0 <= ny && ny < n) {
				if (dist[nx][ny] == -1) {
					dist[nx][ny] = dist[mx][my] + 1;
					q.push(make_pair(nx,ny));
				}
			}
		}
	}
}

int main(void) {
	int t;
	cin >> t;
	while (t--) {
		memset(dist, -1, sizeof(dist));
		cin >> n;
		int a1, a2;
		cin >> a1 >> a2;
		int b1, b2;
		cin >> b1 >> b2;
		bfs(a1, a2);
		cout << dist[b1][b2] << '\n';
	}
	return 0;
}
