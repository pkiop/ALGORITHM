/*
	x,y 좌표를 이용하는 문제. 
	go 함수 안에 모든 y와 x를 x,y로 사용했는데
	계속 답이 317이 나왔다. 
	2차원 배열을 그대로 입력받으면
	행이 x이고 열이 y였다. 
	그래서 x,y 이렇게 쓰는 보통 수학과 달리
	y,x 로 배열에서 입력해주어야
	일반 좌표평면에서 x,y를 표시하는 방법으로
	구할 수 있었다. 

	이렇게 하고싶지 않으면 입력 받을 때 y와 x를
	적절히 바꿔서 하면 되지만 
	
	여러 참고코드를 보거나 종만북에서는 y,x로 
	사용한다. 

	앞으로 이렇게 사용해야 겠다. 

*/


#include <iostream>
#include <cstring>
#include <algorithm>
#include <vector>

using namespace std;

int tb1[1001][1001];
int cache[1001][1001][3]; // 마지막 3은 아래 오른 왼
bool visit[1001][1001];
int n, s, m;

int dx[] = { 0,1,-1 };
int dy[] = { 1,0,0 };

int go(int y,int x,int next) {
	if (y == n - 1 && x == m - 1) {
		return tb1[y][x];
	}
	if (visit[y][x] == true) {
		return -300000;
	}

	int& ret = cache[y][x][next];
	if (ret != -99999) {
		return ret;
	}

	ret = -300000;
	for (int k = 0; k < 3; ++k) {
		int nx = dx[k] + x;
		int ny = dy[k] + y;
		if (0 <= ny && ny < n && 0 <= nx && nx < m) {
			visit[y][x] = true;
			ret = max(ret, go(ny, nx, k)+tb1[y][x]);
			visit[y][x] = false;
		}
	}

	return ret;
}

int main(void) {
	cin >> n >> m; 
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < m; ++j) {
			cin >> tb1[i][j];
			cache[i][j][0] = -99999; // 메모이제이션으로 -1을 쓰면 안될 가능성 
			cache[i][j][1] = -99999;
			cache[i][j][2] = -99999;
		}
	}
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < m; ++j) {
			cout << tb1[i][j] << ' ';	
		}
		cout << endl;
	}
	int ans = go(0, 0, 0);
	cout << ans << endl;

	return 0;
	
}