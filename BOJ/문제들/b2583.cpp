#include <iostream>
#include <vector>
#include <cstring>
#include <algorithm>

using namespace std;

int arr[101][101];
bool visited[101][101];
int dx[] = { 1,-1,0,0 };
int dy[] = {0,0,1,-1 };
int a, b;
int dfscnt;
void dfs(int x,int y) {
	dfscnt++;
	visited[x][y] = true;
	for (int k = 0; k < 4; ++k) {
		int nx = dx[k] + x;
		int ny = dy[k] + y;
		if (0 <= nx && nx <= a && 0 <= ny && ny <= b) {
			if (!visited[nx][ny] && arr[nx][ny] == 1) {
				dfs(nx, ny);
			}
		}
	}
	
}
vector<pair<int, int>> go;
int main(void) {
	memset(arr, -1, sizeof(arr));
	memset(visited, false, sizeof(visited));
	int c;
	cin >> a >> b >> c;
	int k1, k2;//input

	for (int i = 0; i < b; ++i) {
		for (int j = 0; j < a; ++j) {
			arr[j][i] = 1;
		}
	}//일단 1로 채우고 뒤의 사각형으로 0을 채운다. 
	
	for (int i = 0; i < c; ++i) {
		int lx, ly, rx, ry;
		cin >> lx >> ly >> rx >> ry;
		
		rx -= 1;
		ry -= 1;
		for (int ii = ly; ii <= ry; ++ii) {
			for (int jj = lx; jj <= rx; ++jj) {
				arr[ii][jj] = 0;
				visited[ii][jj] = true;
			}
		}
		//cout << '\n';

		//for (int x = 0; x < a; ++x) {
		//	for (int y = 0; y < b; ++y) {
		//		cout << arr[x][y] << ' ';
		//	}
		//	cout << '\n';
		//}
		//cout << "\n\n";
	}

	/*for (int i = 0; i < a; ++i) {
		for (int j = 0; j < b; ++j) {
			cout << arr[i][j] << ' ';
		}
		cout << '\n';
	} */
	int cnt = 0;
	vector<int> dfscntvec;
	for (int i = 0; i < a; ++i) {
		for (int j = 0; j < b; ++j) {
			if (!visited[i][j]) {
				cnt++;
				dfscnt = 0;
				dfs(i, j);
				dfscntvec.push_back(dfscnt);
			}
		}
	}
	
	sort(dfscntvec.begin(), dfscntvec.end());
	cout << cnt << '\n';
	for (int i = 0; i < dfscntvec.size(); ++i) {
		cout << dfscntvec[i] << ' ';
	}
	cout << '\n';
	
	return 0;
}