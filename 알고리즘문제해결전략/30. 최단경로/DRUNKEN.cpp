#include <iostream>
#include <algorithm>
#include <queue>
#include <string>
#include <cstring>

using namespace std;

const int INF = 99999999;

int V, adj[500][500];
// 각 정점에서 음주 운전 단속을 할 때 걸리는 시간

int delay[500];
int W[500][500];

// 입력을 받을 때 1부터 시작하는 정점 번호를 0부터 시작하도록 변경했다고 가정한다.
void solve() {
	vector<pair<int, int> > order;
	for (int i = 0; i < V; ++i) {
		order.push_back({ delay[i],i });
	}
	sort(order.begin(), order.end());
	// 정점을 하나도 거치지 않고 얻을 수 있는 최단경로
	for (int i = 0; i < V; ++i) {
		for (int j = 0; j < V; ++j) {
			if (i == j)
				W[i][j] = 0;
			else
				W[i][j] = adj[i][j];
		}
	}
	int ret = INF;
	for (int k = 0; k < V; ++k) {
		//k 번째로 예상 시간이 적게 걸리는 정점 w까지를 지나서 얻을 수 있는 최단거리
		int w = order[k].second;
		for (int i = 0; i < V; ++i) {
			for (int j = 0; j < V; ++j) {
				adj[i][j] = min(adj[i][j] , adj[i][w] + adj[w][j]);
				W[i][j] = min(adj[i][w] + delay[w] + adj[w][j], W[i][j]);
			}
		}
	}
}

int main(void) {
	
	int b;
	cin >> V >> b;

	for (int i = 0; i < V; ++i) {
		cin >> delay[i];
	}
	for (int i = 0; i < V; ++i) {
		for (int j = 0; j < V; ++j) {
			adj[i][j] = 99999999;
		}
	}
	int a1, a2, a3;
	for (int i = 0; i < b; ++i) {
		cin >> a1 >> a2 >> a3;
		adj[a1-1][a2-1] = a3;
		adj[a2-1][a1-1] = a3;
	}
	
	solve();
	
	int c;
	cin >> c;
	

	for (int i = 0; i < c; ++i) {
		cin >> a1 >> a2;
		cout << W[a1-1][a2-1] << '\n';
	}
	return 0;
}