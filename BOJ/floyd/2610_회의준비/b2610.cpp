#include <iostream>
#include <algorithm>
#include <queue>
#include <string>
#include <cstring>

using namespace std;

const int INF = 99999999;

int V, adj[101][101];
int maxi[101];
bool flag[101];
int gn, rep[101];

void solve() {
	for (int k = 1; k <= V; ++k) {
		for (int i = 1; i <= V; ++i) {
			for (int j = 1; j <= V; ++j) {
				adj[i][j] = min(adj[i][j], adj[i][k] + adj[k][j]);
			}
		}
	}

	for (int i = 1; i <= V; ++i) {
		for (int j = 1; j <= V; ++j) {
			if (adj[i][j] < INF && adj[i][j] > maxi[i])
			maxi[i] = adj[i][j];
		}
	}

	for (int i = 1; i <= V; ++i) {
		if (!flag[i]) {
			int t = i;
			for (int j = i; j <= V; ++j) {
				if (adj[i][j] < INF) {
					flag[j] = true;
					if (maxi[t] > maxi[j]) {
						t = j;
					}
				}
			}
			rep[gn++] = t;
		}
	}
}

int main(void) {
	cin >> V;
	for (int i = 1; i <= V; ++i) {
		for (int j = 1; j <= V; ++j) {
			adj[i][j] = (i == j ? 0 : INF);
		}
	}

	int n;
	cin >> n;
	int a1, a2;
	for (int i = 0; i < n; ++i) {
		cin >> a1 >> a2;
		adj[a1][a2] = 1;
		adj[a2][a1] = 1;
	}

	solve();
	cout << gn << '\n';
	sort(rep, rep + gn);
	for (int i = 0; i < gn; ++i) {
		cout << rep[i] << '\n';
	}
	return 0;
}