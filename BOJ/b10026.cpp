/* 26번째 줄에 괄호 제대로 안쳐서 오랫동안 틀렸다. */ 

#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>
#include <string>

using namespace std;

vector<string> st;
bool visited[102][102];
int n;
int dx[] = { 1,-1,0,0 };
int dy[] = { 0,0,1,-1 };

void dfs_r(int x, int y, char me) {
	visited[x][y] = true;
	for (int k = 0; k < 4; ++k) {
		int nx = x + dx[k];
		int ny = y + dy[k];
		if (0 <= nx && nx < n && 0 <= ny && ny < n) {
			if (!visited[nx][ny]) {
				if ((me == 'R' || me == 'G') && (st[nx][ny] == 'R' || st[nx][ny] == 'G')) {
					dfs_r(nx, ny, me);
				}
				else if(me == 'B' && st[nx][ny] == 'B'){
					dfs_r(nx, ny,me);
				}
			}
		}
	}
}

void dfs_n(int x, int y, char me) {
	visited[x][y] = true;
	for (int k = 0; k < 4; ++k) {
		int nx = x + dx[k];
		int ny = y + dy[k];
		if (0 <= nx && nx < n && 0 <= ny && ny < n) {
			if (!visited[nx][ny] && st[nx][ny] == me) {
				dfs_n(nx, ny, me);
			}
		}
	}
}

int main(void) {
	cin >> n;
	string temp;
	for (int i = 0; i < n; ++i) {
		cin >> temp;
		st.push_back(temp);
	}
	
	int cnt = 0;
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < n; ++j) {
			if (visited[i][j] == false) {
				dfs_n(i, j, st[i][j]);
				cnt++;
			}
		}
	}
	
	cout << cnt << ' ';
	cnt = 0;
	memset(visited, false, sizeof(visited));
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < n; ++j) {
			if (visited[i][j] == false) {
				dfs_r(i, j, st[i][j]);
				cnt++;
			}
		}
	}
	
	cout << cnt << endl;
	return 0;
}