#include <iostream>
#include <vector>
#include <algorithm>
#include <fstream>
#include <string>
#include <cstring>

#define GO
#define DEBUG

using namespace std;

/*

5 4
3 1
3 2
4 3
5 3

*/

vector<int> arr[10001];
bool visited[10001];

int cnt;
void dfs(int x) {
	visited[x] = true;
	int len = arr[x].size();
	for (int i = 0; i < len; ++i) {
		int node = arr[x][i];
		if (visited[node] == false) {
			dfs(node);
			cnt++;
		}
	}
}

int main(void) {

#ifdef GO
	freopen("input.txt", "r", stdin);
#endif
	int n, m;
	cin >> n >> m;
	int a, b;
	for (int i = 0; i < m; ++i) {
		cin >> a >> b;
		arr[b].push_back(a);
	}
	int maxcnt = 0;
	vector<pair<int, int>> anscnt;
	vector<int> out;
	for (int i = 1; i <= n; ++i) {
		memset(visited, false, sizeof(visited));
		cnt = 0;
		dfs(i);
		anscnt.push_back({ cnt,i });
	}

	sort(anscnt.begin(),anscnt.end());
	int len = anscnt.size();
	int cmp = anscnt[len-1].first;
	for (int i = len-1; i >= 0; --i) {
		if (cmp == anscnt[i].first) {
			out.push_back(anscnt[i].second);
		}
		else {
			break;
		}
	}
	sort(out.begin(), out.end());
	len = out.size();
	for (int i = 0; i < len; ++i) {
		cout << out[i] << ' ';
	}


	return 0;

}