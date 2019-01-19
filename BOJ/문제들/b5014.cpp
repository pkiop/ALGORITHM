#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
#include <cstring>
#include <map>
#include <set>

using namespace std;

int cnt1[1000001];
bool visited[1000001];

int main(void) {
	memset(cnt1, 0, sizeof(cnt1));
	int f, s, g, u, d;
	cin >> f >> s >> g >> u >> d;
	bool end = false;
	queue<int> q;
	q.push(s);
	cnt1[s] = 0;
	int ans = -1;
	int nowa;
	while (!q.empty()) {
		nowa = q.front();
		q.pop();
		//data check
		
		if (nowa == g)
		{
			ans = cnt1[nowa];
			break;
		}
		//up경우
		if (nowa + u <= f && u != 0 && visited[nowa+u] == false) {
			cnt1[nowa + u] = cnt1[nowa] + 1;
			visited[nowa + u] = true;
			q.push(nowa + u);
		}
		if (nowa - d > 0 && d != 0 && visited[nowa - d] == false) {
			cnt1[nowa - d] = cnt1[nowa] + 1;
			visited[nowa - d] = true;
			q.push(nowa - d);
		}
	}
	if (ans == -1) {
		cout << "use the stairs" << endl;
	}
	else {
		cout << ans << endl;
	}
	return 0;
}