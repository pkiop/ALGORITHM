// 참고 http://jason9319.tistory.com/119 
// 백준 11400 단절선
#include <vector>
#include <stack>
#include <iostream>
#include <algorithm>

using namespace std;

vector<int> adj[100001];
vector<int> discovered;
int counter = 0;
vector<pair<int, int>> res;

int findCutVertex(int here, int before) {
	discovered[here] = counter++;
	int ret = discovered[here];
	for (int i = 0; i < adj[here].size(); ++i) {
		int there = adj[here][i];
		if (there == before) {
			continue;
		}
		if (discovered[there] == -1) {
			int subtree = findCutVertex(there, here);
			if (subtree > discovered[here])
				res.push_back({ min(here,there),max(here,there) });
			ret = min(ret, subtree);
		}
		else
			ret = min(ret, discovered[there]);
	}
	return ret;
}
int main(void) {
	ios_base::sync_with_stdio(false);
	discovered = vector<int>(100001, -1);
	int n, m;
	cin >> n >> m;
	int a, b;
	for (int i = 0; i < m; ++i) {
		cin >> a >> b;
		adj[a].push_back(b);
		adj[b].push_back(a);
	}
	int cnt = 0;
	vector<int> ans;
	for (int i = 1; i <= n; ++i) {
		if (discovered[i] == -1) {
			counter = 0;
			findCutVertex(i, 0);
		}
	}
	sort(res.begin(), res.end());
	cout << res.size() << '\n';
	for (int i = 0; i < res.size(); ++i) {
		cout << res[i].first << ' ' << res[i].second << '\n';
	}
	return 0;
}