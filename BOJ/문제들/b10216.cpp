#include <iostream>
#include <algorithm>
#include <queue>
#include <vector>
#include <map>
#include <cstring>

using namespace std;

vector<int> adj[3001];
bool visited[3001];

void bfs(int s) {
	visited[s] = true;
	queue<int> q;
	q.push(s);
	while (!q.empty()) {
		int here = q.front();
		q.pop();
		int len = adj[here].size();
		for (int i = 0; i < len; ++i) {
			int next = adj[here][i];
			if (visited[next] == false) {
				q.push(next);
				visited[next] = true;
			}
		}
	}
}

int main(void) {
	int t;
	cin >> t;
	while (t--) {
		int n;
		cin >> n;
		int a[3001], b[3001], r[3001];
		memset(visited, false, sizeof(visited));
		for (int i = 0; i < 3001; ++i) {
			adj[i].clear();
		}
		for (int i = 0; i < n; ++i) {
			cin >> a[i] >> b[i] >> r[i];
		}
		for (int i = 0; i < n; ++i) {
			for (int j = 0; j < n; ++j) {
				if (i != j) {
					int len1 = a[i] - a[j];
					int len2 = b[i] - b[j];
					len1 *= len1;
					len2 *= len2;
					//cout << i << ' ' << j << ' ' << len1 << ' ' << len2 << ' ' << (r[i] + r[j])*(r[i] + r[j]) << '\n';
					if (len1 + len2 <= (r[i] + r[j])*(r[i]+r[j])) {
						//cout << "do" << endl;
						adj[i].push_back(j);
						adj[j].push_back(i);
					}
				}
			}
		}
		int cnt = 0;
		for (int i = 0; i < n; ++i) {
			if (visited[i] == false) {
				bfs(i);
				cnt++;
			}
		}
		cout << cnt << '\n';

	}
	return 0;
}