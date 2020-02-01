#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

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
		if(rank[u] == rank[v]) rank[v]++;

	}
};

int V;
vector<pair<int, int> > adj[200001];
int kruskal(/*vector<pair<int, int> >& selected*/) {
	int ret = 0;
	vector<pair<int, pair<int, int> > > edges;

	for(int u=0;u<V;++u) {
		for(int i=0;i<adj[u].size();++i) {
			int cost = adj[u][i].second;
			int v = adj[u][i].first;
			edges.push_back(make_pair(cost, make_pair(u, v)));
		}
	}

	sort(edges.begin(), edges.end());
	DisjointSet Sets(V);

	for(int i=0;i<edges.size();++i) {
		int u = edges[i].second.first, v = edges[i].second.second;
		int cost = edges[i].first;

		if(Sets.find(u) == Sets.find(v)) continue;
		Sets.merge(u, v);
		//selected.push_back(make_pair(u, v));
		ret += cost; 
	}
	return ret;
}

int main(void) {
	int n;
	cin >> V >> n;
	while(1) {
		int max_c = 0;

		int a,b,c;

		while(n--) {
			cin >> a >> b >> c;

			adj[a].push_back(make_pair(b, c));
			adj[b].push_back(make_pair(a, c));
			max_c += c;

		}
		//vector<pair<int, int > > selected;
		cout << max_c - kruskal() << endl;

		/*for(int i=0;i<selected.size();++i) {
			cout << selected[i].first << ' ' << selected[i].second << endl;
		}*/


		cin >> V >> n;
		if(V == 0 && n == 0) {
			break;
		}
		for(int i=0;i<V;++i) {
			adj[i].clear();
		}
	}
	return 0;
}
