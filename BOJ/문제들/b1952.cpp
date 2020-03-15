#include <iostream>

using namespace std;

int dx[] = {1, 0, -1, 0};
int dy[] = {0, 1, 0, -1};
int arr[101][101];

int main(void) {
	int n, m;
	cin >> n >> m;
	int pos = 0;
	int now_x = 0;
	int now_y = 0;
	int c_pos = 0;
	while(1) {
		//cout << now_x << ' ' << now_y << endl;
		while(now_x >= 0 && now_x < m && now_y >= 0 && now_y < n && arr[now_x][now_y] == 0) {
			arr[now_x][now_y] = 1;
			now_x = now_x + dx[pos];
			now_y = now_y + dy[pos];
		}
		now_x = now_x - dx[pos];
		now_y = now_y - dy[pos];
		arr[now_x][now_y] = 0;
		//cout << now_x << ' ' << now_y << endl;

		pos++;
		c_pos++;
		if(pos == 4) {
			pos = 0;
		}
		bool cont = false;
		for(int k=0;k<4;++k) {
			int nx = now_x + dx[k];
			int ny = now_y + dy[k];
			if(nx >= 0 && nx < m && ny >= 0 && ny < n && arr[nx][ny] == 0) {
				cont = true;
			}
		}
		if(cont == true) {		
			continue;
		}
		break;
	}
	cout << --c_pos << endl;
	return 0;

}
