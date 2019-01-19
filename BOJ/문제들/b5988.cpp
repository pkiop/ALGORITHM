#include <iostream>
#include <vector>
#include <queue>
#include <stack>
#include <algorithm>
#include <fstream>
#include <string>
#include <cstring>
#include <map>

#define pii pair<int, int>
#define pli pair<long, int>
#define mii map<int, int>
#define msi map<string, int>

typedef unsigned long long ull;
typedef long long ll;

using namespace std;



#define GO
#define DEBUG


/*

5 21
-3 2 -4 -1 -5

*/
vector<vector<int>> arr;
int visited[110001];
bool vis[110001];
int n;
queue<int> q;
void go(int x) {
	q.push(x);
	visited[x] = 1;
	vis[x] = true;
	while (!q.empty()) {
		int node = q.front();
		q.pop();

		if (node == n)
			break;

		int len = arr[node].size();
		for (int i = 0; i < len; ++i) {
			int sel = arr[node][i];
			if (vis[sel] == false) {
				visited[sel] = visited[node] + 1;
				vis[sel] = true;
				q.push(sel);
			}
		}
	}
}

int main(void) {
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#ifdef GO
	freopen("input.txt", "r", stdin);
#endif



//main

	int k, m;
	cin >> n >> k >> m;
	for (int i = 1; i <= 110000; ++i) {
		visited[i] = 999999999;
	}
	arr.resize(n + m + 1);
	int in;
	for (int i = n+1; i < m+n+1; ++i) {
		for (int j = 0; j < k; ++j) {
			cin >> in;
			arr[i].push_back(in);
			arr[in].push_back(i);
		}
	}


	go(1);

	cout << (visited[n] == 999999999 ? -1 : visited[n]/2+1) << '\n';

	//clear
	











#ifdef GO
	cout << "\nerase go\n";
#endif

	return 0;
}