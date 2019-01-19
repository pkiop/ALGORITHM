#include <vector>
#include <stack>
#include <iostream>
#include <algorithm>

using namespace std;

vector<int> adj[10001];
vector<int> discovered;
vector<bool> isCutVertex;
int counter = 0;

int findCutVertex(int here, bool isRoot) {
	discovered[here] = counter++;
	int ret = discovered[here];
	int children = 0;
	for (int i = 0; i < adj[here].size(); ++i) {
		int there = adj[here][i];
		if (discovered[there] == -1) {
			++children;
			int subtree = findCutVertex(there, false);
			if (!isRoot && subtree >= discovered[here])
				isCutVertex[here] = true;
			ret = min(ret, subtree);
		}
		else
			ret = min(ret, discovered[there]);
			
	}
	if (isRoot) isCutVertex[here] = (children >= 2);
	return ret;
}
int main(void) {
	ios_base::sync_with_stdio(false);
	discovered = vector<int>(10001, -1);
	isCutVertex = vector<bool>(10001, false);
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
			findCutVertex(i, true);
		}
	}
	for (int i = 1; i <= n; ++i) {
		if (isCutVertex[i] == true) {
			cnt++;
			ans.push_back(i);
		}
	}
	cout << cnt << '\n';
	//debuging => ans.size() - 1 을 했는데 단위가 size_t 인가 그래서 INT_MAX로 갔다.
	for (int i = 0; i < ans.size(); ++i) {
		cout << ans[i] << ' ';
	}
	
	return 0;
}