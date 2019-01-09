#include <iostream>
#include <queue>
#include <algorithm>
#include <cstring>

using namespace std;

int map[50][50];
bool visited[50][50];

int dx[4] = { 1,-1,0,0 };
int dy[4] = { 0,0,1,-1 };

int main() {

	ios_base::sync_with_stdio(false);
	int N, L, R;
	bool chk = true;
	
	int ans = 0;
	queue<pair<int, int>> q;   
	queue<pair<int, int>> uni; 

	cin >> N >> L >> R;

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++)
			cin >> map[i][j];
	}

	while (chk) {
		chk = false; 
		ans++;
		memset(visited, false, sizeof(visited));

		for (int i = 0; i < N; i++) {
			for (int j = 0; j < N; j++) {
				if (visited[i][j]) 
					continue;

				int sum = map[i][j];

				q.push({ j,i });
				uni.push({ j,i });
				visited[i][j] = 1;

				while (!q.empty()) {
					int x_tmp = q.front().first;
					int y_tmp = q.front().second;
					q.pop();

					for (int k = 0; k < 4; k++) {
						int x = x_tmp + dx[k];
						int y = y_tmp + dy[k];

						if (x < 0 || y < 0 || x >= N || y >= N || visited[y][x] || abs(map[y_tmp][x_tmp] - map[y][x]) < L || abs(map[y_tmp][x_tmp] - map[y][x]) > R)
							continue;

						chk = true;
						q.push({ x,y });
						uni.push({ x,y });
						sum += map[y][x];
						visited[y][x] = 1;
					}

				}


				int avr = sum / uni.size();

				while (!uni.empty()) {
					map[uni.front().second][uni.front().first] = avr;
					uni.pop();
				}
			}
		}

	}
	cout << ans - 1;
}
