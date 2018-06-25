#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <math.h>

using namespace std;

const int MAX_V = 20001;
const double INF = 9999999.0;

int V; // 정점의 개수

vector<pair<double, int> > adj[MAX_V];
vector<double> dijkstra(int src) {
	vector<double> dist(V, INF);
	dist[src] = 0.0;
	priority_queue<pair<double, int> > pq;
	pq.push(make_pair(0.0, src));
	while (!pq.empty()) {
		double cost = -pq.top().first;
		int here = pq.top().second;
		pq.pop();
		//만약 지금 꺼낸 것보다 더 짧은 경로를 알고 있다면 지금 꺼낸 것을 무시한다.
		if (dist[here] < cost) continue;
		//인접한 정점 모두 검사
		for (int i = 0; i < adj[here].size(); ++i) {
			int there = adj[here][i].second;
			double nextDist = cost + log(adj[here][i].first);
			//cout << nextDist << endl;
			//더 짧은 경로를 발견하면 dist[]를 갱신하고 우선순위 큐에 넣는다.
			if (dist[there] > nextDist) {
				dist[there] = nextDist;
				pq.push(make_pair(-nextDist, there));
			}

		}
	}
	return dist;
}

int main(void) {
	int t;
	cin >> t;
	int a, b;
	double c;
	cout.precision(10);	
	cout << fixed;
	while (t--) {
		int m;
		cin >> V >> m;
		for (int i = 0; i < m; ++i) {
			cin >> a >> b >> c;
			adj[a].push_back(make_pair(c, b));
			adj[b].push_back(make_pair(c, a));
		}

		vector<double> ansvector = dijkstra(0);
		cout << exp(ansvector[V - 1]) << '\n';
		for (int i = 0; i < V; ++i) {
			adj[i].clear();
		}
	}
	return 0;
}
