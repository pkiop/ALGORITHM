#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
#include <cstring>

using namespace std;

int adj[126][126];
int dist[126][126];
int n;
int dx[] = { 1,-1,0,0 };
int dy[] = { 0,0,1,-1 };

void dij() {
	dist[0][0] = adj[0][0];

	priority_queue < pair< int, pair<int,int> > > pq;
	pq.push({ -dist[0][0],{0,0} });
	while (!pq.empty()) {
		int cost = -pq.top().first;
		int herex = pq.top().second.first;
		int herey = pq.top().second.second;
		pq.pop();

		if (dist[herex][herey] < cost && dist[herex][herey] != -1) {
			continue;
		}
		if (dist[herex][herey] == -1) {
			dist[herex][herey] = cost;
		}

		for (int k = 0; k < 4; ++k) {
			int nx = dx[k] + herex;
			int ny = dy[k] + herey;
			if (0 <= nx && nx < n && 0 <= ny && ny < n) {
				int nextdist = cost + adj[nx][ny];
				if (nextdist < dist[nx][ny] || dist[nx][ny] == -1) {
					dist[nx][ny] = nextdist;
					pq.push({ -nextdist, {nx,ny} });
				}
			}
		}
	}
}

int main(void) {
	while (1) {
		cin >> n;
		if (n == 0) {
			break;
		}
		memset(adj, -1, sizeof(adj));
		memset(dist, -1, sizeof(dist));
		for (int i = 0; i < n; ++i) {
			for (int j = 0; j < n; ++j) {
				cin >> adj[i][j];
			}
		}
		dij();
		static int i = 1;
		cout << "Problem " << i << ": "  << dist[n - 1][n - 1] << endl;
		i++;
		
	}
}