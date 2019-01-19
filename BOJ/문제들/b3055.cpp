#include <iostream>
#include <cstring>
#include <string>
#include <algorithm>
#include <vector>
#include <queue>

using namespace std;

char arr[51][51];
int dist[51][51];
int gox[] = { 1,-1,0,0 };
int goy[] = { 0,0,1,-1 };
int dx;
int dy;
int sx;
int sy;
int wx, wy;
int r, c;
bool second = false, ans = false;
int mindist = 99999;

void print_dist() {
	for (int i = 0; i < r; ++i) {
		for (int j = 0; j < c; ++j) {
			cout << dist[i][j] << ' ';
		}
		cout << endl;
	}
}
void bfs(int x,int y) {
	queue<pair<int, int> > q;
	dist[x][y] = 0;
	q.push(make_pair(x,y));
	while (!q.empty()) {
//		print_dist();
		int mx = q.front().first;
		int my = q.front().second;
		q.pop();
		for (int k = 0; k < 4; ++k) {
			int nx = mx + gox[k];
			int ny = my + goy[k];
			if (0 <= nx && nx < r && 0 <= ny && ny < c) {
				if (second == true && arr[nx][ny] == 'D') {
					ans = true;
					mindist = min(mindist, dist[mx][my]);
				}
				if ((dist[nx][ny] == -1 && arr[nx][ny] == '.') || (dist[nx][ny] > dist[mx][my] + 1 && arr[nx][ny] == '.')) {
					q.push(make_pair(nx, ny));
					dist[nx][ny] = dist[mx][my] + 1;
				}
			}
		}	
	}
}

int main(void) {
	vector<pair<int, int> > waterloc;
	memset(dist, -1, sizeof(dist));
	cin >> r >> c;
	for (int i = 0; i < r; ++i) {
		cin >> arr[i];
	}
	for (int i = 0; i < r; ++i) {
		for (int j = 0; j < c; ++j) {
			if (arr[i][j] == 'S') {
				dx = i;
				dy = j;
			}
			if (arr[i][j] == '*') {
				waterloc.push_back(make_pair(i, j));
			}
		}
	}
//	print_dist();
	for (int i = 0; i < waterloc.size(); ++i) {
		bfs(waterloc[i].first,waterloc[i].second);
	}
	second = true;
//	print_dist();
	bfs(dx, dy);
//	print_dist();
	if (ans == true)
		cout << mindist+1 << endl;
	else
		cout << "KAKTUS" << endl;
	return 0;

}