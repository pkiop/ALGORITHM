//[위상정렬] 백준 2623 음악 프로그램

#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>

using namespace std;

vector<int> adj[1001];
bool visited[1001];
vector<int> order;

void dfs(int x) {
	visited[x] = true;
	for (int i = 0; i < adj[x].size(); ++i) {
		int next = adj[x][i];
		if (!visited[next]) {
			dfs(next);
		}
	}
	order.push_back(x);
}

int a, b;

vector<int> topo() {

	order.clear();
	memset(visited, false, sizeof(visited));
	for (int i = 1; i <= a; ++i) {
		if(!visited[i])
			dfs(i);
	}
	reverse(order.begin(), order.end());

	//사이클 확인하는 코드 좀더 효율적으로 짤 필요
	for (int i = 1; i <= a; ++i) {
		int len = adj[i].size();
		for (int j = 0; j < len; ++j) {
			int aaa = i, bbb = adj[i][j];
			bool aa = false;
			for (int k = 0; k < order.size(); ++k) {
				if (aaa == order[k]) {
					aa = true;
				}
				if (aa == false && order[k] == bbb) {
					return vector<int>();
				}
			}
			aa = false;
		}
	}
		
	return order;
}

int main(void) {
	cin >> a >> b;
	for (int i = 0; i < b; ++i) {
		int aa;
		int bb, cc;
		cin >> aa;
		if (aa == 1) {
			cin >> aa;//받고 아무것도 안해도 된다.
		}
		else {
			cin >> bb;
			for (int j = 0; j < aa-1; ++j) {
				cin >> cc;
				adj[bb].push_back(cc);
				bb = cc;
			}
		}
	}

	vector<int> ans = topo();
	if (ans.size() == 0) {
		cout << 0;
		return 0;
	}
	for (int i = 0; i < ans.size(); ++i) {
		cout << ans[i] << '\n';
	}
	return 0;
}