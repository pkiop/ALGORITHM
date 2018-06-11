#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
#include <cstring>
#include <map>
#include <set>

using namespace std;

int r, c;
char arr[251][251];
bool visited[251][251];
int dx[] = { 0,0,1,-1 };
int dy[] = { 1,-1,0,0 };

int yang;
int wolf;
void bfs(int x, int y) {
	visited[x][y] = true;
	queue<pair<int, int> > q;
	q.push(make_pair(x, y));
	while (!q.empty()) {
		int mx = q.front().first;
		int my = q.front().second;
		if (arr[mx][my] == 'o') {
			yang += 1;
		}
		if (arr[mx][my] == 'v') {
			wolf += 1;
		}
		q.pop();
		for (int k = 0; k < 4; ++k) {
			int nx = mx + dx[k];
			int ny = my + dy[k];
			if (0 <= nx && nx < r && 0 <= ny && ny < c) {
				if (arr[nx][ny] != '#' && visited[nx][ny] == false) {
					visited[nx][ny] = true;
					q.push(make_pair(nx, ny));
				}
			}
		}
	}
}

int main(void) {
	cin >> r >> c;
	memset(visited, false, sizeof(visited));
	for (int i = 0; i < r; ++i) {
		for (int j = 0; j < c; ++j) {
			cin >> arr[i][j];
		}
	}
	int maxyang = 0;
	int maxwolf = 0;
	for (int i = 0; i < r; ++i) {
		for (int j = 0; j < c; ++j) {
			if (arr[i][j] != '#' && visited[i][j] == false) {
				yang = 0;
				wolf = 0;
				bfs(i, j);
				if (yang > wolf) {
					maxyang += yang;
				}
				else {
					maxwolf += wolf;
				}
			}
		}
	}
	cout << maxyang << ' ' << maxwolf;
	return 0;


}