#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int N, M;
vector<pair<int, int> > adj[100001];

struct DisjointSet {
	vector<int> parent, rank;
	DisjointSet(int n) : parent(n), rank(n, 1) {
		for(int i=0;i<n;++i) {
			parent[i] = i;
		}
	}

	int find(int u) {
		if(u == parent[u]) return u;
		return parent[u] = find(parent[u]);
	}

	void merge(int u, int v) {
		u = find(u), v = find(v);
		if(u == v) return;
		if(rank[u] > rank[v]) swap(u, v);
		parent[u] = v;
		if(rank[u] == rank[v]) rank[u]++;
	}
};
int max_cost = 0;
int kruskal(/*vector<pair<int, int> >& selected*/) {
	int ret = 0;
	vector<pair<int, pair<int, int > > > edges;

	for(int u=1;u<=N;++u) {
		for(int i = 0; i < adj[u].size(); ++i) {
			int v = adj[u][i].first, cost = adj[u][i].second;
			edges.push_back(make_pair(cost, make_pair(u, v) ) );
		}
	}
	sort(edges.begin(), edges.end());

	DisjointSet sets(N+1);

	for(int i=0;i<edges.size();++i) {
		int cost = edges[i].first;
		int u = edges[i].second.first, v = edges[i].second.second;
		if(sets.find(u) == sets.find(v)) continue;
		sets.merge(u, v);
		ret += cost;
		max_cost = cost;
	}
	return ret;

}



int main(void) {

	freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	cin >> N >> M;
	int a,b,c;
	for(int i=0;i<M;++i) {
		cin >> a >> b >> c;
		adj[a].push_back({b, c});
		adj[b].push_back({a, c}); 
	}
	cout << kruskal() - max_cost << endl;
	return 0;
}
