#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
#include <cstring>

using namespace std;

char arr[11][11];
int visited[11][11][11][11]; // 앞 두개 빨강 x,y 뒤 두개 파랑 x,y

class pos {
public:
	int rx, ry, bx, by; // red xy, blue xy
};

int main(void) {
	memset(visited, -1, sizeof(visited));
	int r, c;
	cin >> r >> c;
	int redx, redy, bluex, bluey;
	for (int i = 0; i < r; ++i) {
		for (int j = 0; j < c; ++j) {
			cin >> arr[j][i];
			if (arr[j][i] == 'R') {
				redx = j;
				redy = i;
			}
			if (arr[j][i] == 'B') {
				bluex = j;
				bluey = i;
			}
		}
	}

	//for (int i = 0; i < r; ++i) {
	//	for (int j = 0; j < c; ++j) {
	//		cout << arr[j][i] << ' ';
	//	}
	//	cout << endl;
	//}
	//cout << redx << ' ' << redy << ' ' << bluex << ' ' << bluey << endl;
	queue<pos> q;
	q.push({ redx,redy,bluex,bluey });
	visited[redx][redy][bluex][bluey] = 0;
	while (!q.empty()) {
		pos here = q.front();
		q.pop();
		int nowlen = visited[here.rx][here.ry][here.bx][here.by];
		if (nowlen > 9) {
			cout << "-1";
			return 0;
		}
		
		//왼쪽 기울이기
		bool redfirst;
		if (here.rx < here.bx) {
			redfirst = true;
		}
		else {
			redfirst = false;
		}
		int move_rx = here.rx;
		bool redgoal = false;
		bool bluegoal = false;
		bool failon = false;
		while (arr[move_rx][here.ry] != '#') {
			if (arr[move_rx][here.ry] == 'O') {
				redgoal = true;
			}
			move_rx--;
		}
		move_rx++;
		int move_bx = here.bx;
		while (arr[move_bx][here.by] != '#') {
			if (arr[move_bx][here.by] == 'O') {
				bluegoal = true;
			}
			move_bx--;
		}
		move_bx++;

		if (redgoal && !bluegoal) {
			cout << nowlen + 1;
			return 0;
		}
		if (bluegoal) {
			failon = true;
		}

		if (move_rx == move_bx && here.ry == here.by) {
			if (redfirst) {
				move_bx++;
			}
			else {
				move_rx++;
			}
		}

		if (visited[move_rx][here.ry][move_bx][here.by] == -1 && !failon) {
			visited[move_rx][here.ry][move_bx][here.by] = visited[here.rx][here.ry][here.bx][here.by] + 1;
			q.push({ move_rx,here.ry,move_bx,here.by });
		}


		//오른쪽 기울이기
		redgoal = false;
		bluegoal = false;
		failon = false;
		
		if (here.rx > here.bx) {
			redfirst = true;
		}
		else {
			redfirst = false;
		}
		move_rx = here.rx;
		while (arr[move_rx][here.ry] != '#') {
			if (arr[move_rx][here.ry] == 'O') {
				redgoal = true;
			}
			move_rx++;
		}
		move_rx--;
		move_bx = here.bx;
		while (arr[move_bx][here.by] != '#') {
			if (arr[move_bx][here.by] == 'O') {
				bluegoal = true;
			}
			move_bx++;
		}
		move_bx--;

		if (redgoal && !bluegoal) {
			cout << nowlen + 1;
			return 0;
		}
		if (bluegoal) {
			failon = true;
		}

		if (move_rx == move_bx && here.ry == here.by) {
			if (redfirst) {
				move_bx--;
			}
			else {
				move_rx--;
			}
		}

		if (visited[move_rx][here.ry][move_bx][here.by] == -1 && !failon) {
			visited[move_rx][here.ry][move_bx][here.by] = visited[here.rx][here.ry][here.bx][here.by] + 1;
			q.push({ move_rx,here.ry,move_bx,here.by });
		}

		//위쪽 기울이기
		redgoal = false;
		bluegoal = false;
		failon = false;
		if (here.ry < here.by) {
			redfirst = true;
		}
		else {
			redfirst = false;
		}
		int move_ry = here.ry;
		while (arr[here.rx][move_ry] != '#') {
			if (arr[here.rx][move_ry] == 'O') {
				redgoal = true;
			}
			
			move_ry--;
		}
		move_ry++;

		int move_by = here.by;
		while (arr[here.bx][move_by] != '#') {
			if (arr[here.bx][move_by] == 'O') {
				bluegoal = true;
			}
			move_by--;
		}
		move_by++;

		if (redgoal && !bluegoal) {
			cout << nowlen + 1;
			return 0;
		}
		if (bluegoal) {
			failon = true;
		}

		if (here.rx == here.bx && move_ry == move_by) {
			if (redfirst) {
				move_by++;
			}
			else {
				move_ry++;
			}
		}

		if (visited[here.rx][move_ry][here.bx][move_by] == -1 && !failon) {
			visited[here.rx][move_ry][here.bx][move_by] = visited[here.rx][here.ry][here.bx][here.by] + 1;
			q.push({ here.rx,move_ry,here.bx,move_by });
		}


		//아래쪽 기울이기
		redgoal = false;
		bluegoal = false;
		failon = false;
		if (here.ry > here.by) {
			redfirst = true;
		}
		else {
			redfirst = false;
		}
		move_ry = here.ry;
	
		while (arr[here.rx][move_ry] != '#') {
			if (arr[here.rx][move_ry] == 'O') {
				redgoal = true;
			}

			move_ry++;
		}
		move_ry--;

		move_by = here.by;
		while (arr[here.bx][move_by] != '#') {
			if (arr[here.bx][move_by] == 'O') {
				bluegoal = true;
			}
			move_by++;
		}
		move_by--;

		if (redgoal && !bluegoal) {
			cout << nowlen + 1;
			return 0;
		}
		if (bluegoal) {
			failon = true;
		}

		if (here.rx == here.bx && move_ry == move_by) {
			if (redfirst) {
				move_by--;
			}
			else {
				move_ry--;
			}
		}

		if (visited[here.rx][move_ry][here.bx][move_by] == -1 && !failon) {
			visited[here.rx][move_ry][here.bx][move_by] = visited[here.rx][here.ry][here.bx][here.by] + 1;
			q.push({ here.rx,move_ry,here.bx,move_by });
		}


	}

	cout << "-1" << endl;
	return 0;
}