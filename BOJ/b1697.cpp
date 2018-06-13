#include <iostream>
#include <queue>

using namespace std;

const int MAX = 100001;

struct Data {
	int lo, cnt;
};

bool visited[100001];

int main(void) {
	int a, b;
	cin >> a >> b;
	queue<Data> q;
	q.push({ a,0 });
	while (1) {
		Data now = q.front();
		q.pop();
		if (now.lo == b) {
			cout << now.cnt;
			return 0;
		}
		if (visited[now.lo]) {
			continue;
		}
		visited[now.lo] = true;
		//teleport
		if (2 * now.lo < MAX) {
			q.push({ 2 * now.lo,now.cnt + 1 });
		}
		//walk
		if (now.lo + 1 < MAX) {
			q.push({ now.lo + 1,now.cnt + 1 });
		}
		if (now.lo - 1 >= 0) {
			q.push({ now.lo - 1,now.cnt + 1 });
		}
		
	}
}