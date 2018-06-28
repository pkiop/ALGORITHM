#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <cstring>

using namespace std;

vector<pair<int, int> > adj[402];
int n;
int V;
const int START = 401;
const int INF = 987654321;

vector<int> dijkstra(int src) {
	vector<int> dist(V, INF);
	dist[src] = 0;
	priority_queue<pair<int, int> > pq;
	pq.push({ 0,src });
	while (!pq.empty()) {
		int cost = -pq.top().first;
		int here = pq.top().second;
		pq.pop();

		if (cost > dist[here]) continue;

		for (int i = 0; i < adj[here].size(); ++i) {
			int there = adj[here][i].first;
			int nextDist = cost + adj[here][i].second;
			if (dist[there] > nextDist) {
				dist[there] = nextDist;
				pq.push({ -nextDist,there });
			}
		}
	}
	return dist;
}
//(A국 선수의 예상시간 - B국 선수의 예상시간) 의 정점 번호를 반환한다.

int vertex(int delta) {
	return delta + 200;
}

int solve(const vector<int>& a, const vector<int>& b) {
	//그래프를 만든다.
	V = 402;
	for (int i = 0; i < V; ++i) adj[i].clear();
	for (int i = 0; i < a.size(); ++i) {
		int delta = a[i] - b[i];
		adj[START].push_back({ vertex(delta),a[i] });
	}

	//현재 차이
	for (int delta = -200; delta <= 200; ++delta) {
		//i번 종목을 뒤에 붙인다면?
		for (int i = 0; i < a.size(); ++i) {
			int next = delta + a[i] - b[i];
			if (abs(next) > 200) continue;
			adj[vertex(delta)].push_back({ vertex(next),a[i] });
		}
	}
	vector<int> shortest = dijkstra(START);
	int ret = shortest[vertex(0)];
	if (ret == INF) return -1;
	return ret;
}


int main(void) {
	int t;
	cin >> t;
	while (t--) {
		cin >> n;
		int a, b;
		vector<int> acon;
		vector<int> bcon;
		for (int i = 0; i < n; ++i) {
			cin >> a >> b;
			acon.push_back(a);
			bcon.push_back(b);
		}
		int ans = solve(acon, bcon);
		if (ans == -1) {
			cout << "IMPOSSIBLE" << endl;
		}
		else
			cout << solve(acon, bcon) << endl;
	}
	return 0;
}