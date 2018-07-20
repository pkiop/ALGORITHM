#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
using namespace std;


const int MAX_V = 100001;
const int INF = 987654321;
//정점의 개수
int V;
//그래프의 인접 리스트, (연결된 정점 번호, 간선 가중치) 쌍을 담는다.
vector<pair<int, int> > adj[MAX_V];

double prim(vector<pair<int, int> >& selected) {
	selected.clear();
	//해당 정점이 트리에 포함되어 있나?
	vector<bool> added(V+1, false);
	//트리에 인접한 간선 중 해당 정점에 닿는 최소 간선의 정보를 저장
	vector<int> minWeight(V+1, INF);
	vector<int> parent(V+1, -1);
	//가중치의 합을 저장할 변수
	int ret = 0;
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
			int weight = adj[u][i].second;
			if (!added[v] && minWeight[v] > weight) {
				parent[v] = u;
				minWeight[v] = weight;
			}
		}
	}
	return ret;
}

int lo[100001][3];

int dist(int a, int b) {
	int ret = 999999999;
	for (int k = 0; k < 3; ++k) {
		ret = min(abs(lo[a][k] - lo[b][k]),ret);
	}
	return ret;
}

int main(void) {
	
	int n;
	cin >> n;
	V = n;
	
	for (int i = 0; i < n; ++i) {
		for (int k = 0; k < 3; ++k) {
			cin >> lo[i][k];
		}
	}

	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < n; ++j) {
			adj[i].push_back({ j,dist(i,j) });
		}
	}
	
	vector<pair<int, int>> selected;
	cout << prim(selected) << endl;

	
	return 0;
}