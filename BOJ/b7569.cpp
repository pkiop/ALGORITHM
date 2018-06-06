#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <cstring>
#include <string>
#include <map>

using namespace std;
int arr[101][101][101];
int dist[101][101][101];
int dx[] = {0,0,1,-1,0,0};
int dy[] = {0,0,0,0,1,-1};
int dz[] = {1,-1,0,0,0,0};

int m, n, h;
void bfs(int x, int y, int z) {
	dist[x][y][z] = 0;
	queue<pair<int, pair<int, int> > > q;
	q.push(make_pair(x, make_pair(y, z)));
	while (!q.empty()) {
		int mx = q.front().first;
		int my = q.front().second.first;
		int mz = q.front().second.second;
		q.pop();
		for (int k = 0; k < 6; ++k) {
			int nx = mx + dx[k];
			int ny = my + dy[k];
			int nz = mz + dz[k];
			if (0 <= nx && nx < m && 0 <= ny && ny < n && 0 <= nz && nz < h) {
				if ((dist[nx][ny][nz] == -1 && arr[nx][ny][nz] == 0) || (arr[nx][ny][nz] == 1 && dist[nx][ny][nz] > dist[mx][my][mz] + 1)) {
					dist[nx][ny][nz] = dist[mx][my][mz] + 1;
					arr[nx][ny][nz] = 1;
					q.push(make_pair(nx, make_pair(ny, nz)));
				}
			}
		}
	}
}
int main(void) {
	memset(dist, -1, sizeof(dist));
	cin >> m >> n >> h;
	vector<int> x,y,z;
	for (int k = 0; k < h; ++k) {
		for (int i = 0; i < n; ++i) {
			for (int j = 0; j < m; ++j) {
				cin >> arr[j][i][k];
				if (arr[j][i][k] == 1) {
					x.push_back(j);
					y.push_back(i);
					z.push_back(k);
				}
			}
		}
	}
	int len = x.size();
	for (int i = 0; i < len; ++i) {
		bfs(x[i], y[i], z[i]);
	}
	//for (int k = 0; k < h; ++k) {
	//	for (int i = 0; i < n; ++i) {
	//		for (int j = 0; j < m; ++j) {
	//			cout << dist[j][i][k] << ' ';
	//		}
	//		cout << endl;
	//	}
	//}
	//cout << endl;
	//for (int k = 0; k < h; ++k) {
	//	for (int i = 0; i < n; ++i) {
	//		for (int j = 0; j < m; ++j) {
	//			cout << arr[j][i][k] << ' ';
	//		}
	//		cout << endl;
	//	}
	//}

	int maxlen = 0;
	for (int k = 0; k < h; ++k) {
		for (int i = 0; i < n; ++i) {
			for (int j = 0; j < m; ++j) {
				if (arr[j][i][k] == 0) {
					cout << -1;
					return 0;
				}
				maxlen = max(maxlen, dist[j][i][k]);
			}
		}
	}
	
	
	cout << maxlen;
}