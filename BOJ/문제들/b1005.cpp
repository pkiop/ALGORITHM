//백준 1005 
// 만들어야 하는 건물 에서 dfs 해서 제일 시간 오래 걸리는 곳 까지 탐색

#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>

using namespace std;

int fb;//final building
int bt[1010]; //build time
//vector<int> adj[1010];
vector<int> jda[1010];
int dp[1010];
bool ch_fb = false;

bool visited[1001];

vector<int> order;

int dfs(int x) {
	if (jda[x].size() == 0) {
		return bt[x];
	}
	int& ret = dp[x];
	if (ret != -1) {
		return ret;
	}

	ret = 0;
	int N_idx;
	for (N_idx = 0; N_idx < jda[x].size(); ++N_idx) {
		ret = max(dfs(jda[x][N_idx]) + bt[x], ret);
	}
	
	return ret;
}

//위상정렬 포기
//void ddfs(int x) {
//	visited[x] = true;
//	int temp;
//	for (int next = 0; next < adj[x].size(); ++next) {
//		temp = adj[x][next];
//		if (visited[temp] == false) {
//			dfs(temp);
//		}
//	}
//	order.push_back(temp);
//}
//int a, b;
//void topologicalSort() {
//	int n = a;
//	memset(visited, false, sizeof(visited));
//	order.clear();
//	for (int i = 1; i <= n; ++i) {
//		if (!visited[i]) {
//			dfs(i);
//		}
//	}
//	reverse(order.begin(), order.end());
//	return ;
//}

int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int k1, k2;//for input
	int t;
	cin >> t;
	while (t--) {
		for (int i = 0; i < 1010; ++i) {
			jda[i].clear();
		}

		memset(dp, -1, sizeof(dp));
		memset(bt, -1, sizeof(bt));

		int a, b;
		cin >> a >> b;

		for (int i = 1; i <= a; ++i) {
			cin >> bt[i];
		}
		for (int i = 0; i < b; ++i) {
			cin >> k1 >> k2;
			//adj[k1].push_back(k2);
			jda[k2].push_back(k1);
		}
		cin >> fb;

		cout << dfs(fb) << '\n';
		
		//for (int i = 1; i <= a; ++i) {
		//	cout << dp[i] << ' ';
		//}
		//cout << "끝" << endl; /*debugging*/
	}

}