// [DFS] 백준 14502 연구소

#include <iostream>
#include <vector>
#include <cstring>
#include <algorithm>

using namespace std;

int ori[9][9];//original
int adj[9][9];
int ans[9][9];
bool visited[9][9];
int n,m;
int dx[] = { 1,-1,0,0 };
int dy[] = { 0,0,1,-1 };

vector<pair<int, int>> virus;
vector<pair<int, int>> build_wall;

void dfs(int x,int y) {
	adj[x][y] = 2;
	for (int k = 0; k < 4; ++k) {
		int nx = x + dx[k];
		int ny = y + dy[k];
		if (0 <= nx && nx <= n && 0 <= ny && ny <= m) {
			if (adj[nx][ny] == 0) {
				dfs(nx, ny);
			}
		}
	}
}

void ori_copy(void) {
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < m; ++j) {
			adj[i][j] = ori[i][j];
		}
	}
}

int main(void){
	memset(adj, -1, sizeof(adj));
	cin >> n >> m;
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < m; ++j) {
			cin >> ori[i][j];
			if (ori[i][j] == 2) {
				virus.push_back(make_pair(i, j));
			}
			if (ori[i][j] == 0) {
				build_wall.push_back(make_pair(i, j));
			}
		}
	}
	int max_cnt = 0;
	int len = build_wall.size();
	for (int i = 0; i < len; ++i) {
		for (int j = i+1; j < len; ++j) {
			for (int k = j + 1; k < len; ++k) {
				ori_copy();
				int first_wall_x = build_wall[i].first;
				int first_wall_y = build_wall[i].second;
				int second_wall_x = build_wall[j].first;
				int second_wall_y = build_wall[j].second;
				int third_wall_x = build_wall[k].first;
				int third_wall_y = build_wall[k].second;
				adj[first_wall_x][first_wall_y] = 1;
				adj[second_wall_x][second_wall_y] = 1;
				adj[third_wall_x][third_wall_y] = 1;
				int virus_len = virus.size();
				for (int i = 0; i < virus_len; ++i) {
					int virus_location_x = virus[i].first;
					int virus_location_y = virus[i].second;
					dfs(virus_location_x, virus_location_y);
				}
				int cnt = 0;
				for (int ii = 0; ii < n; ++ii) {
					for (int jj = 0; jj < m; ++jj) {
						if (adj[ii][jj] == 0) {
							cnt++;
						}
					}
				}
				max_cnt = max(cnt, max_cnt);
			}
		}
	}
	cout << max_cnt << endl;



	return 0;
}