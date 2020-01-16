#include <iostream>
#include <queue>

using namespace std;

int horse_jx[] = {1, 2, 2, 1, -1, -2, -2, -1};
int horse_jy[] = {2, 1, -1, -2, -2, -1, 1, 2};

int dx[] = {0,0,1,-1};
int dy[] = {1,-1,0,0};

int table[201][201];

int K;
int X,Y;

struct lo {
	int x,y,cnt,chance;
};

int visited[201][201][31];

bool range_ch(int x, int y) {
	if(0 <= x && x < X && 0 <= y && y < Y) {
		if(table[x][y] == 0){
			return true;
		}
	}
	return false;
}

bool bfs() {
	queue<lo> q;
	q.push({0, 0, 0, K});
	visited[0][0][K] = 0;
	while(!q.empty()){
		int now_x = q.front().x;
		int now_y = q.front().y;
		int now_cnt = q.front().cnt;
		int now_chance = q.front().chance;
		//cout << now_x << ' ' << now_y << endl;
		q.pop();
		if(now_x == X-1 && now_y == Y-1) {
			cout << now_cnt << endl;
			return true;
		}


		if(now_chance > 0) {
			for(int k=0;k<8;++k){
				int next_x = now_x + horse_jx[k];
				int next_y = now_y + horse_jy[k];
				if(!range_ch(next_x, next_y))
					continue;
				if(visited[next_x][next_y][now_chance-1] > visited[now_x][now_y][now_chance] + 1){
					visited[next_x][next_y][now_chance-1] = visited[now_x][now_y][now_chance] + 1;
					q.push({next_x, next_y, now_cnt+1, now_chance-1});
				}
				else{
					continue;
				}
				
			}
		}

		for(int k=0;k<4;++k){
			int next_x = now_x + dx[k];
			int next_y = now_y + dy[k];
			if(!range_ch(next_x, next_y))
				continue;
			if(visited[next_x][next_y][now_chance] > visited[now_x][now_y][now_chance] + 1){
				visited[next_x][next_y][now_chance] = visited[now_x][now_y][now_chance] + 1;
				q.push({next_x, next_y, now_cnt+1, now_chance});
			}
			else{
				continue;
			}
		}
	}
	return false;
}

int main(void) {
	for(int i=0;i<201;++i){
		for(int j=0;j<201;++j){
			for(int k=0;k<31;++k){
				visited[i][j][k] = 99999999;
			}
		}
	}
	cin >> K >> X >> Y;

	for(int y=0;y<Y;++y){
		for(int x=0;x<X;++x){
			cin >> table[x][y];
		}
	}

	if(!bfs()){
		cout << -1 << endl;
	}
	return 0;
}
