#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <cstring>
#include <string>
#include <map>

using namespace std;

char arr[251][251];
bool visited[251][251];
int dx[] = { 0,0,1,-1 };
int dy[] = { 1,-1,0,0 };
int n, m;
int yang;
int wolf;

void bfs(int x, int y) {
	
	queue<pair<int, int> > q;
	q.push(make_pair(x, y));
	while (!q.empty()) {
		int mx = q.front().first;
		int my = q.front().second;
		q.pop();
		visited[mx][my] = true;
		if (arr[mx][my] == 'v') {
			wolf++;
		}
		if (arr[mx][my] == 'k') {
			yang++;
		}
		for (int k = 0; k < 4; ++k) {
			int nx = mx + dx[k];
			int ny = my + dy[k];
			if (0 <= nx && nx < n && 0 <= ny && ny < m) {
				if (visited[nx][ny] == false && arr[nx][ny] != '#') {
					q.push(make_pair(nx, ny));
					visited[nx][ny] = true; //여기서 방문체크 하지 않으면 방문했던 점을 여러번 갈 수 있다. 
				}
			}
		}
	}
}
void print() {
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < m; ++j) {
			cout << visited[i][j] << ' ';
		}
		cout << endl;
	}
}
int main(void) {
	cin >> n >> m;
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < m; ++j) {
			cin >> arr[i][j];
		}
	}
	
	int ansyang = 0;
	int answolf = 0;
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < m; ++j) {
			yang = 0;
			wolf = 0;
			if (arr[i][j] != '#' && visited[i][j] == false) {
				bfs(i, j);
		/*		cout << "좌표 " << i << ' ' << j << endl;
				cout << "yang : " << yang << endl;
				cout << "wolf : " << wolf << endl;
				print();*/
			}
			if (yang > wolf) {
				ansyang += yang;
			}
			else {
				answolf += wolf;
			}
		}
	}

	cout << ansyang << ' ' << answolf;
	return 0;
}