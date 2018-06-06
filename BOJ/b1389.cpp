#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <cstring>

using namespace std;

vector<int> arr[101];
queue<int> q;
int dist[101];

void bfs(int start) {
	dist[start] = 0;
	q.push(start);
	while (!q.empty()) {
		int here = q.front();
		q.pop();
		for (int i = 0; i < arr[here].size(); ++i) {
			int next = arr[here][i];
			if (dist[next] == -1) {
				dist[next] = dist[here] + 1;
				q.push(next);
			}
		}
	}
}
int main(void) {
	int n, m;
	cin >> n >> m;
	int t1, t2;
	for (int i = 0; i < m; ++i) {
		cin >> t1 >> t2;
		arr[t1].push_back(t2);
		arr[t2].push_back(t1);
	}
	int reidx = 0;
	int remin = 100000000;
	for (int i = 1; i <= n; ++i) {
		memset(dist, -1, sizeof(dist));
		bfs(i);
		int sum = 0;
		for (int j = 1; j <= n; ++j) {
			if (i == j) {
				continue;
			}
			sum += dist[j];
		}
		if (remin > sum) {
			reidx = i;
			remin = sum;
		}
	}
	cout << reidx << '\n';
	return 0;
}