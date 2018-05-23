// [DFS] 백준 11403 경로찾기

#include <iostream>
#include <vector>
#include <cstring>

using namespace std;

int adj[101][101];
int ans[101][101];
bool visited[101];
int n;

bool first_on;
void dfs(int x,int first) {
	if (first == x && first_on) {
		ans[x][x] = 1;
	}
	else {
		first_on = true;
	}
	visited[x] = true;
	for (int i = 1; i <= n; ++i) {
		if ((!visited[i] || first == i) && adj[x][i] == 1) {
			dfs(i,first);
		}
	}
}

int main(void) {
	cin >> n;
	for (int i = 1; i <= n; ++i) {
		for (int j = 1; j <= n; ++j) {
			cin >> adj[i][j];
		}
	}
	for (int i = 1; i <= n; ++i) {
		for (int j = 1; j <= n; ++j) {
			memset(visited, false, sizeof(visited));
			first_on = false;
			dfs(i,i);
			if (visited[j]) {
				if (i != j) {
					ans[i][j] = 1;
				}
			}
		}
	}
	for (int i = 1; i <= n; ++i) {
		for (int j = 1; j <= n; ++j) {
			cout << ans[i][j] << ' ';
		}
		cout << '\n';
	}
	return 0;
}