#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <cstring>

using namespace std;

int arr[301][301];
bool visited[301][301];
int n, m;
int dx[] = { 1,-1,0,0 };
int dy[] = { 0, 0, 1 ,-1 };

void minus1(void) {
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < m; ++j) {
			if (arr[i][j] != 0) {
				for (int k = 0; k < 4; ++k) {
					int nx = i + dx[k];
					int ny = j + dy[k];
					if (0 <= nx && nx < n && 0 <= ny && ny < m)
						if(arr[nx][ny] == 0 && visited[nx][ny] == false && arr[i][j] != 0)
							arr[i][j]--;
				}
				visited[i][j] = true;
			}
		}
	}
}

void dfs(int x, int y) {
	visited[x][y] = true;
	for (int k = 0; k < 4; ++k) {
		int nx = x + dx[k];
		int ny = y + dy[k];
		if (0 <= nx && nx < n && 0 <= ny && ny < m) {
			if (!visited[nx][ny] && arr[nx][ny] != 0) {
				dfs(nx, ny);
			}
		}
	}
}

void printarr(void) {
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < m; ++j) {
			cout << arr[i][j] << ' ';
		}
		cout << '\n';
	}
}
int main(void) {
	int maxh = 0;
	cin >> n >> m;
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < m; ++j) {
			cin >> arr[i][j];
			maxh = max(maxh, arr[i][j]);
		}
	}
	int maxcnt = 0;
	
	for (int i = 0; i < 500; ++i) {
		memset(visited, false, sizeof(visited));
		int cnt = 0;
		for (int x = 0; x < n; ++x) {
			for (int y = 0; y < m; ++y) {
				if (visited[x][y] == false && arr[x][y] != 0) {
					dfs(x, y);
					cnt++;
				}
			}
		}
		if (cnt >= 2) {
			cout << i << '\n';
			return 0;
		}
		memset(visited, false, sizeof(visited));
		minus1();
		//cout << cnt << '\n';
		//printarr();
		
	}
	cout << 0 << '\n';
	return 0;

}