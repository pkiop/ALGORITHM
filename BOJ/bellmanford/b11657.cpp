#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

const int MAX_V = 500;
const int INF = 987654321;
vector<pair<int, int> > adj[MAX_V];
int n, m;

vector<int> bellmanford(int src) {
	n += 1;
	vector<int> upper(n, INF);
	upper[src] = 0;

	bool updated;
	for (int iter = 0; iter < n; ++iter) {
		updated = false;
		for (int here = 0; here < n; ++here) {
			for (int i = 0; i < adj[here].size(); ++i) {
				int there = adj[here][i].first;
				int cost = adj[here][i].second;

				if (upper[there] > upper[here] + cost) {
					upper[there] = upper[here] + cost;
					updated = true;
				}
			}
		}
		if (!updated) {
			break;
		}
	}
	if (updated) {
		upper.clear();
	}
	return upper;
}

int main(void) {
	cin >> n >> m;
	int a, b, c;
	for (int i = 0; i < m; ++i) {
		cin >> a >> b >> c;
		adj[a].push_back({ b,c });
	}
	vector<int> result = bellmanford(1);
	if (result.size() == 0) {
		cout << -1 << endl;
		return 0;
	}
	for (int i = 2; i <= n-1; ++i) {
		if (result[i] == INF) {
			cout << -1 << endl;
			continue;
		}
		cout << result[i] << '\n';
	}
	return 0;
}
