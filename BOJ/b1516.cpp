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
vector<int> adj[501];
int dp[1010];
bool ch_fb = false;

bool visited[1001];

vector<int> order;

int dfs(int x) {

	int& ret = dp[x];
	if (ret != -1) {
		return ret;
	}
	ret = 0;
	for (int i = 0; i < adj[x].size(); ++i) {
		int next = adj[x][i];
		ret = max(ret,bt[next] + dfs(next));
	}
	return ret;
}

int main(void)
{
	memset(dp, -1, sizeof(dp));
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int t;
	cin >> t;
	int k1=0;//for input
	for(int i=1;i<=t;++i){
		cin >> k1;
		bt[i] = k1;
		while (1) {
			cin >> k1;
			if (k1 == -1) {
				break;
			}
			adj[i].push_back(k1);
		}
	}
	
	for (int i = 1; i <= t; ++i) {
		cout << dfs(i) + bt[i] << '\n';
	}

}