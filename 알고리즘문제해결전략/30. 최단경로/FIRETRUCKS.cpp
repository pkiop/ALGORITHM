#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <queue>

using namespace std;

const int MAX_N = 1001;
const int INF = 987654321;

vector<vector<pair<int, int> > > adj;
int fire[1001];
int office[1001];

int v, e, n, m;
int dijkstra() {
	vector<int> dist(v+1, INF);
	priority_queue<pair<int, int> > pq;
	for (int i = 0; i < m; ++i) {
		dist[office[i]] = 0;
		pq.push({ 0,office[i]});
	} 

	while (!pq.empty()) {
		int cost = -pq.top().first;
		int here = pq.top().second;
		pq.pop();

		if (cost > dist[here]) {
			continue;
		}

		for (int i = 0; i < adj[here].size(); ++i) {
			int there = adj[here][i].first;
			int nextDist = cost + adj[here][i].second;
			if (nextDist < dist[there]) {
				dist[there] = nextDist;
				pq.push({ -nextDist,there });
			}
		}
	}
	int ans = 0;
	for (int i = 0; i < n; ++i) {
		ans += dist[fire[i]];
	}
	return ans;
}

int main(void) {
	int t;
	cin >> t;
	while (t--) {
		int a, b, c;
		cin >> v >> e >> n >> m;
		adj.clear();
		adj.resize(v + 1);
		for (int i = 0; i < e; ++i) {
			cin >> a >> b >> c;
			adj[a].push_back({ b,c });
			adj[b].push_back({ a,c });
		}
		for (int i = 0; i < n; ++i) {
			cin >> fire[i];
		}
		for (int i = 0; i < m; ++i) {
			cin >> office[i];
		}
		cout << dijkstra() << endl;
		for (int i = 0; i < v+1; ++i) {
			adj[i].clear();
		}
	}
	return 0;
}