#include <iostream>
#include <list>

using namespace std;

list<pair<int, int>> snake;
bool tb2[1001][1001];
int turn = 0;//0 : 동 1 : 남 2 : 서 3 : 북 시계뱡향으로 증가 
int tsize; // 뱀게임 판 크기
int nowtime = 0;
int playtime = 0;
bool gameset = false;

bool find(int nx, int ny) {
	list<pair<int, int>>::iterator it;
	for (it = snake.begin(); it != snake.end(); ++it) {
		/*cout << it->first << ' ' << it->second << endl;*/
		if (it->first == nx && it->second == ny) {
			return true;
		}
	}
	return false;
}

void print_list() {
	
	list<pair<int, int>>::iterator it;
	for (it = snake.begin(); it != snake.end(); ++it) {
		cout << it->first << ' ' << it->second << endl;
	
	}
}
int go(int min) {
	int x;
	int y;

	if (turn == 0) {
		x = 1;
		y = 0;
	}
	else if (turn == 1) {
		x = 0;
		y = 1;
	}
	else if (turn == 2) {
		x = -1;
		y = 0;
	}
	else {
		x = 0;
		y = -1;
	}

	for (int i = 0; i < min; ++i) {
		int nx = x + snake.back().first;
		int ny = y + snake.back().second;
	//	cout << nx << "  " << ny << endl;

		if (1 <= nx && nx <= tsize && 1 <= ny && ny <= tsize && !find(nx, ny)) { //
			playtime++;
			snake.push_back(make_pair(nx, ny));
			if (tb2[nx][ny] == false) {
				if (!snake.empty()) {
					snake.pop_front();
				}
			}
			else {
				tb2[nx][ny] = false;
			}
		}
		else {
			playtime++;
			//cout << "ch : << " << nx << ' ' << ny << endl;
			//cout << turn << endl;
			return -1;
		}
	}
	return 0;
}

int main(void) {

	cin >> tsize;

	int n1, n2;
	cin >> n1;
	for (int i = 1; i <= n1; ++i) { // apple's location
		int a, b;
		cin >> b >> a;
		tb2[a][b] = true;
	}

	cin >> n2;
	snake.push_back(make_pair(1, 1));
	for (int i = 0; i < n2; ++i) {//snake's turn
		int a;
		char b;
		cin >> a >> b;
		int gotime = a - nowtime;
		if (go(gotime) == -1) {
			gameset = true;
			break;
		};
		nowtime += gotime;
		if (b == 'D') { //
			if (turn == 3) {
				turn = 0;
			}
			else {
				turn++;
			}
		}
		else {
			if (turn == 0) {
				turn = 3;
			}
			else {
				turn--;
			}
		}
	}
	if (!gameset) {
		go(10001);
	}
	cout << playtime << endl;
	//print_list();
	return 0;
}