#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <cstring>
#include <queue>

using namespace std;

int arr[1001][1001];
int visited[1001][1001][2];
int dx[] = { 0,0,1,-1 };
int dy[] = { 1,-1,0,0 };
int a, b;

struct dd {
	int x, y, z;
};
int main(void) {
	cin >> a >> b;
	memset(visited, -1, sizeof(visited));
	for (int i = 0; i < a; ++i) {
		for (int j = 0; j < b; ++j) {
			scanf("%1d", &arr[i][j]);
		}
	}

	queue<dd> q;
	q.push({ 0,0,0 });
	visited[1001][1001][0] = true;
	while (!q.empty()) {
		dd here = q.front();
		q.pop();
		if (here.x == a - 1 && here.y == b - 1) {
			if (visited[a - 1][b - 1][0] != -1) {
				cout << 2+visited[a - 1][b - 1][0] << '\n';
			}
			else {
				cout << 2+visited[a - 1][b - 1][1] << '\n';
			}
			return 0;
		}

		for (int k = 0; k < 4; ++k) {
			int nx = here.x + dx[k];
			int ny = here.y + dy[k];
			if (0 <= nx && nx < a && 0 <= ny && ny < b) {
				if (arr[nx][ny] == 0 && visited[nx][ny][here.z] == -1) {
					q.push({ nx,ny,here.z });
					visited[nx][ny][here.z] = visited[here.x][here.y][here.z] + 1;
				}
				if (arr[nx][ny] == 1 && here.z == 0 && visited[nx][ny][1] == -1) {
					q.push({ nx,ny,1 });
					visited[nx][ny][1] = visited[here.x][here.y][here.z] + 1;
				}
			}
		}
	}
	cout << -1 << endl;
	return 0;
}