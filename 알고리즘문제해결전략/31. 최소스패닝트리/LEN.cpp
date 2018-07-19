#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
using namespace std;
int arr[120001];
bool goodnum[120001];

const int MAX_V = 501;
const int INF = 987654321;
//정점의 개수
int V;
//그래프의 인접 리스트, (연결된 정점 번호, 간선 가중치) 쌍을 담는다.
vector<pair<int, double> > adj[MAX_V];

double prim(vector<pair<int, double> >& selected) {
	selected.clear();
	//해당 정점이 트리에 포함되어 있나?
	vector<bool> added(V, false);
	//트리에 인접한 간선 중 해당 정점에 닿는 최소 간선의 정보를 저장
	vector<double> minWeight(V, INF);
	vector<int> parent(V, -1);
	//가중치의 합을 저장할 변수
	double ret = 0;
	//0번 정점을 시작점으로 : 항상 트리에 가장 먼저 추가한다.
	minWeight[0] = parent[0] = 0;
	for (int iter = 0; iter < V; ++iter) {
		//다음에 트리에 추가할 정점 u를 찾는다.
		int u = -1;
		for (int v = 0; v < V; ++v) {
			if (!added[v] && (u == -1 || minWeight[u] > minWeight[v]))
				u = v;
		}
		//(parent[u],u) 를 트리에 추가한다.
		if (parent[u] != u)
			selected.push_back(make_pair(parent[u], u));
		ret += minWeight[u];
		added[u] = true;

		//u에 인접한 간선 u,v를 검사
		for (int i = 0; i < adj[u].size(); ++i) {
			int v = adj[u][i].first;
			double weight = adj[u][i].second;
			if (!added[v] && minWeight[v] > weight) {
				parent[v] = u;
				minWeight[v] = weight;
			}
		}
	}
	return ret;
}

int xlo[501];
int ylo[501];

double dist(int a, int b) {
	double ret = sqrt((xlo[b] - xlo[a]) * (xlo[b] - xlo[a]) + (ylo[b] - ylo[a]) * (ylo[b] - ylo[a]));
	return ret;
}

int main(void) {
	int t;
	cin >> t;
	while (t--) {
		int n, m;
		cin >> n >> m;
		V = n;
		for (int i = 0; i < n; ++i) {
			cin >> xlo[i];
		}
		for (int i = 0; i < n; ++i) {
			cin >> ylo[i];
		}
		for (int i = 0; i < n; ++i) {
			for (int j = 0; j < n; ++j) {
				if (i == j)
					continue;
				adj[i].push_back({ j,dist(i,j) });
			}
		}
		int s, e;
		for (int j = 0; j < m; ++j) {
			cin >> s >> e;
			for (int i = 0; i < adj[s].size(); ++i) {
				if (adj[s][i].first == e) {
					adj[s][i].second = 0;
				}
			}
			for (int i = 0; i < adj[e].size(); ++i) {
				if (adj[e][i].first == s) {
					adj[e][i].second = 0;
				}
			}
		}
		vector<pair<int, double>> selected;
		cout.fixed;
		cout.precision(11);
		cout << prim(selected) << endl;
		for (int i = 0; i < n; ++i) {
			adj[i].clear();
		}
	}
	return 0;
}