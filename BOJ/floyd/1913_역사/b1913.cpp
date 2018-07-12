#include <iostream>
#include <algorithm>
#include <queue>
#include <string>
#include <cstring>

using namespace std;

int adj[405][405], n, k, s;
int main() {
	cin >> n >> k;
	for (int i = 1; i <= k; i++) {
		int a, b;
		cin >> a >> b;
		adj[a][b] = -1;
	}
	for (int k = 1; k <= n; k++) {
		for (int i = 1; i <= n; i++) {
			for (int j = 1; j <= n; j++) {
				if (adj[i][k] == -1 && adj[k][j] == -1) 
					adj[i][j] = -1;
			}
		}
	}
	cin >> s;
	for (int i = 1; i <= s; i++) {
		int a, b;
		cin >> a >> b;
		if (adj[a][b] == -1) cout << "-1\n";
		else if (adj[b][a] == -1) cout << "1\n";
		else cout << "0\n";
	}
	return 0;
}


