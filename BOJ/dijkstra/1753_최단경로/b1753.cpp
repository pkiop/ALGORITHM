#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <queue>

using namespace std;

/*
	다익스트라 알고리즘 

	BFS랑 유사하지만 경로가 1이 아니라 2~3번 깊이로 들어가도 1번째 깊이보다 
	거리가 짧을 수 있음.
	이러한 것 때문에 그냥 Q의 우선순위 처리로는 문제 해결할 수 가 없다.
	사용하는 것이 priority queue
	
	STL priority queue는 가장 값이 큰 것이 우선순위가 높게 측정된다. 음수로 바꿔서 반대로 되도록
	pair<int, int> 를 사용한다면 앞에 거리를 넣어야 한다. 앞원소 기준으로 우선순위 측정 

*/

const int MAX_V = 20001;
const int INF = 999999;

int n, m;
vector<pair<int, int> > adj[MAX_V];

vector<int> dijkstra(int src) {
	vector<int> dist(1+n, INF);
	dist[src] = 0;
	priority_queue<pair<int, int> > pq;
	pq.push({ 0,src });
	while (!pq.empty()) {
		int here = pq.top().second;
		int cost = -pq.top().first;
		pq.pop();
		if (cost > dist[here]) continue;

		for (int i = 0; i < adj[here].size(); ++i) {
			int there = adj[here][i].first;
			int nextDist = adj[here][i].second + cost;
			if (dist[there] > nextDist) {
				dist[there] = nextDist;
				pq.push({ -nextDist,there });
			}
		}
	}
	return dist;
}

int main(void) {
	int start;
	int a, b, c;
	cin >> n >> m >> start;
	for (int i = 0; i < m; ++i) {
		cin >> a >> b >> c;
		adj[a].push_back({ b,c });
	}
	vector<int> ans(n);
	ans = dijkstra(start);
	for (int i = 1; i <= n; ++i) {
		if (ans[i] == INF) {
			cout << "INF\n";
			continue;
		}
		cout << ans[i] << '\n';
	}
	return 0;
}