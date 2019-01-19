#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <stack>
#include <queue>
#include <cstring>
using namespace std;

int n, m;
vector<int> adj[200];
int arr1[200], arr2[200];
bool visited[200];
bool dfs(int x) {
	visited[x] = true;
	for (int i = 0; i < adj[x].size(); ++i) {
		if (arr2[adj[x][i]] == -1 || !visited[arr2[adj[x][i]]] && dfs(arr2[adj[x][i]]))
		{
			arr1[x] = adj[x][i];
			arr2[adj[x][i]] = x;
			return true;
		}
	}
	return false;
}
int main(void) {
	cin >> n >> m;
	for (int i = 0; i < n; ++i) {
		int s;
		cin >> s;
		for (int j = 0; j < s; ++j) {
			int k;
			cin >> k;
			adj[i].push_back(k - 1);
		}
	}

	int match = 0;
	memset(arr1, -1, sizeof(arr1));
	memset(arr2, -1, sizeof(arr2));
	for (int i = 0; i < n; ++i) {
		if (arr1[i] == -1) {
			memset(visited, false, sizeof(visited));
			if (dfs(i)) match++;
		}
	}
	cout << match << endl;
	return 0;

}