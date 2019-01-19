#include <iostream>
#include <queue>
#include <map>
#include <algorithm>

using namespace std;

const int MAX = 100001;
bool visited[100001];

struct Data {
	int lo, cnt;
};

map<int, int> m;

int main(void) {
	int a, b;
	cin >> a >> b;
	queue<Data> q;
	q.push({ a,0 });
	int endcnt = MAX+1;
	int anscnt = 0;
	bool first = false;
	int ret = MAX;
	while (!q.empty()) {
		Data now = q.front();
		//cout << now.lo << ' ' << now.cnt << endl;
		q.pop();
		visited[now.lo] = true;
		if (now.lo == b) {
			m[now.cnt]++;
			ret = min(ret, now.cnt);
		}
		//teleport
		if (2 * now.lo < MAX && (visited[now.lo*2] == false)) {
			q.push({2*now.lo,now.cnt+1});
		}
		//walk
		if (now.lo+1 < MAX && (visited[now.lo+1] == false)) {
			q.push({1 +now.lo,now.cnt + 1 });
		}
		if (now.lo-1 >= 0 && (visited[now.lo-1 ] == false)) {
			q.push({ now.lo - 1,now.cnt + 1 });
		}
	}
	cout << ret << '\n' << m[ret];
	
	return 0;
}