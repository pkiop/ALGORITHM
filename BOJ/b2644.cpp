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
	int n;
	memset(dist, -1, sizeof(dist));
	cin >> n;
	int a, b;
	cin >> a >> b;
	int t;
	cin >> t;
	int t1, t2;
	
	while (t--) {
		cin >> t1 >> t2;
		arr[t1].push_back(t2);
		arr[t2].push_back(t1);
	}
	bfs(a);
	cout << dist[b] << '\n';
	return 0;
}