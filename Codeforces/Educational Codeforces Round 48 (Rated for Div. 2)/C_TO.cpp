#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <cstring>
#include <cassert>

using namespace std;

typedef long long ll;

const int MAX = 1000000000 + 1;
int arr[1000001][2];
int box[1000001];
int snake[1000001];
int n;
/*
void cal_box_data() {
	box[n - 1] = arr[n - 1][0] * arr[n - 1][1];
	for (int i = n - 2; i >= 0; --i) {
		box[i] = box[i + 1] + arr[i][0] * arr[i][1];
	}
}

void cal_snake_data() {
	snake[0] = 0;
	int ni = 0;
	int nj = 1;
	for (int i = 1; i < n; ++i) {
		snake[i] = snake[i - 1] + arr[i - 1][ni] * arr[i - 1][nj] + arr[i - 1][nj] * arr[i][nj];
		swap(ni, nj);
	}
}
*/
int sndp[1000001];
void cal_snake() {
	sndp[0] = 0;
	int y = 0;
	for (int i = 1; i < n; ++i) {
		sndp[i] = sndp[i - 1] + arr[i - 1][(y + 1)%2]*(y * 2 + 1) + arr[i][(y+1)%2] * (y*2 + 2);
		y++;
	}
}


int cal_box(int x, int y, int cnt) {
	int ret = 0;
	for (int i = x + 1; i < n; ++i) {
		ret += cnt * arr[i][y % 2];
		cnt++;
	}
	for (int i = n - 1; i >= x; --i) {
		ret += cnt * arr[i][(y + 1) % 2];
		cnt++;
	}
	//cout << "box ret : " << ret << endl;
	return ret;
}

int main(void) {
	cin >> n;
	for (int at = 0; at < 2; ++at) {
		for (int i = 0; i < n; ++i) {
			cin >> arr[i][at];
		}
	}
	int max_ans = 0;
	int ret = 0;
	int yy = 0;
	cal_snake();
	for (int i = 0; i < n; ++i) {
	//	cout << "snake_ret : " << sndp[i] << endl;
		ret = sndp[i] + cal_box(i, yy % 2, i * 2+1);
	//	cout << "real ret : " << ret << endl;
		max_ans = max(max_ans, ret);
		yy++;
	}
	cout << max_ans << endl;
}