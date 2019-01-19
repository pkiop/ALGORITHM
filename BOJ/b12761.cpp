#include <iostream>
#include <vector>
#include <algorithm>
#include <fstream>
#include <string>
#include <cstring>
#include <queue>

#define GO

using namespace std;

int a, b, n, m;
bool visited[100001];

int main(void) {

#ifdef GO
	freopen("input.txt", "r", stdin);
#endif
	//B Ffirst Search // Depth FS
	cin >> a >> b >> n >> m;
	queue<pair<int, int> > q;
	q.push({ n,0 });
	visited[n] = true;
	while (!q.empty()) {
		int now = q.front().first;
		int cnt = q.front().second;
		q.pop();

		if (now == m) {
			cout << cnt;
			return 0;
		}

		int cal[] = { now + 1, now - 1, now + a, now - a, now + b, now - b, now * a, now * b };
		for (int i = 0; i < 8; ++i) {
			if (cal[i] >= 0 && cal[i] <= 100000) {
				if (visited[cal[i]] == false) {
					visited[cal[i]] = true;
					q.push({ cal[i], cnt + 1 });
				}
			}
		}
	}

	return 0;
}