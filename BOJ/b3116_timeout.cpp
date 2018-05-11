#include <iostream>
#include <map>

using namespace std;

int drx[9] = { 0,-1,0,1,1,1,0,-1,-1 };
int dry[9] = { 0,1,1,1,0,-1,-1,-1,0 };
struct bug {
	int x;
	int y;
	int dr;
	void move() {
		x += drx[dr];
		y += dry[dr];
	}
};
const int settime = 2000000;
bug bg[5001];
int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	int n;
	cin >> n;
	for (int i = 0; i < n; ++i) {
		int a, b, c;
		cin >> a >> b >> c;
		bg[i].x = a;
		bg[i].y = b;
		bg[i].dr = c;
	}
	map<int, int> m;
	int max_ans = 0;
	int min_time = settime;
	for (int i = 1; i < settime; ++i) {
		int ans = 0;
		for (int i = 0; i < n; ++i) {
			bg[i].move();
		}
		for (int j = 0; j < n; ++j) {
			if(m[bg[j].x] == bg[j].y)
				ans++;
			else
				m[bg[j].x] = bg[j].y;
		}
		if (ans > max_ans) {
			max_ans = ans;
			min_time = i;
		}
	}
	cout << max_ans << '\n' << min_time << endl;
	return 0;
}