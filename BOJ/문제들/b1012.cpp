#include <iostream>
#include <cstring>
#include <string>
#include <algorithm>
#include <vector>
#include <queue>

using namespace std;

int dx[] = { 0,0,1,-1 };
int dy[] = { 1,-1,0,0 };
int arr[51][51];
bool visited[51][51];
vector<pair<int, int> > start;

int aa, bb, cc;

void bfs(int x, int y) {
	queue<pair<int, int> > q;
	q.push(make_pair(x, y));
	visited[x][y] = true;

	while (!q.empty()) {
		int mx = q.front().first;
		int my = q.front().second;
		q.pop();
		for (int k = 0; k < 4; ++k) {
			int nx = mx + dx[k];
			int ny = my + dy[k];
			if (0 <= nx && nx < aa && 0 <= ny && ny < bb) {
				if (visited[nx][ny] == false && arr[nx][ny] == 1) {
					q.push(make_pair(nx, ny));
					visited[nx][ny] = true;
				}
			}
		}
	}
}

int main(void) {
	int t;
	int t1, t2;

	cin >> t;
	while (t--) {
		memset(arr, 0, sizeof(arr));
		memset(visited, false, sizeof(visited));
		start.clear();
		cin >> aa >> bb >> cc;
		for (int i = 0; i < cc; ++i) {
			cin >> t1 >> t2;
			start.push_back(make_pair(t1, t2));
			arr[t1][t2] = 1;
		}
		int nx, ny;
		int cnt = 0;
		for (int i = 0; i < start.size(); ++i) {
			nx = start[i].first;
			ny = start[i].second;
			if (visited[nx][ny] == false) {
				bfs(nx, ny);
				cnt++;
			}
		}
		cout << cnt << '\n';
	}
	return 0;
}