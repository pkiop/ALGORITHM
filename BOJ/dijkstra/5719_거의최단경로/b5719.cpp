#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
#include <cstring>

using namespace std;

const int INF = 99099999;
int adj[501][501];
int dist[501];
int n, m;
int s, e;

void dij(int src) {
	priority_queue<pair<int, int> > pq;
	pq.push({ 0,src });

	while (!pq.empty()) {
		int cost = -pq.top().first;
		int here = pq.top().second;
		pq.pop();

		if (cost > dist[here] && dist[here] != -1)
			continue;
		if (dist[here] == -1) {
			dist[here] = cost;
		}
		for (int i = 0; i < n; ++i) {
			if (adj[here][i] == -1) {
				continue;
			}

			int nextDist = cost + adj[here][i];
			int there = i;
			if (nextDist < dist[there] || dist[there] == -1) {
				pq.push({ -nextDist, there });
				dist[there] = nextDist;
			}
		}
	}
}

void eraseEdge() {
	queue<int> q;
	q.push(e);
	while (!q.empty()) {
		int here = q.front();
		q.pop();
		for (int i = 0; i < n; ++i) {
			int mdist = dist[here];
			if (mdist == dist[i] + adj[i][here] && adj[i][here] != -1) {
				adj[i][here] = -1;
				q.push(i);
			}
		}
	}
}

int main(void) {
	int a1, b1, c1;
	while (1) {
		memset(adj, -1, sizeof(adj));
		cin >> n >> m;
		if (n == 0 && m == 0) {
			break;
		}

		cin >> s >> e;
		for (int i = 0; i < m; ++i) {
			cin >> a1 >> b1 >> c1;
			adj[a1][b1] = c1;
		}
		memset(dist, -1, sizeof(dist));
		dij(s);

		eraseEdge();
		memset(dist, -1, sizeof(dist));
		dij(s);
		cout << dist[e] << endl;
	}
	return 0;
}