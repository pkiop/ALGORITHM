#include <iostream>
#include <algorithm>
#include <queue>
#include <cstring>

using namespace std;

int _data[51][51];
int N, L, R;
int move_x[] = { 1,-1,0,0 };
int move_y[] = { 0, 0, 1, -1 };
queue<pair<int, int> > groupInfo;
queue<pair<int, int> > temp;
bool visit[51][51];
int ans = 0;

void input() {
	cin >> N >> L >> R;

	for (int i = 0; i < N; ++i) {
		for (int j = 0; j < N; ++j) {
			cin >> _data[i][j];
		}
	}
}

void dfs(int x, int y) {
	for (int k = 0; k < 4; ++k) {
		int next_x = x + move_x[k];
		int next_y = y + move_y[k];
		if (0 > next_x || 0 > next_y || N <= next_x && N <= next_y)
			continue;
		int diff = abs(_data[x][y] - _data[next_x][next_y]);
		if (diff >= L && diff <= R && !visit[next_x][next_y]) {
			groupInfo.push(make_pair(next_x, next_y));//  Fanam
			visit[next_x][next_y] = true;
			dfs(next_x, next_y);
		}
	}
}

int SumandDiv(int x, int y) {
	int ret = 0;
	groupInfo.push(make_pair(x, y));

	int divvalue = groupInfo.size();
	cout << divvalue << ' ' << "gropusize" << endl;
	while (!groupInfo.empty()) {
		int xx = groupInfo.front().first;
		int yy = groupInfo.front().second;
		groupInfo.pop();
		temp.push(make_pair(xx, yy));
		ret += _data[xx][yy];
	}
	int calval = ret / divvalue;
	//put new value
	while (!temp.empty()) {
		int xx = temp.front().first;
		int yy = temp.front().second;
		temp.pop();
		_data[xx][yy] = calval;
	}
}

void DB_print_all__data() {
	for (int i = 0; i < N; ++i) {
		for (int j = 0; j < N; ++j) {
			cout << _data[i][j] << ' ';
		}
		cout << endl;
	}

}

void visitClear() {
	memset(visit, false, sizeof(visit));
}

void processing() {
	bool onedo = true;
	while (onedo) {
		onedo = false;
        visitClear();
		DB_print_all__data();
		for (int i = 0; i < N; ++i) {
			for (int j = 0; j < N; ++j) {
                if(visit[i][j] == false)
                    dfs(i, j);
				if (!groupInfo.empty()) {
					ans++;
					onedo = true;
					SumandDiv(i, j);
				}
			}
		}
	}
}




int main()
{
	input();
	processing();
	cout << ans << endl;



	return 0;
}
