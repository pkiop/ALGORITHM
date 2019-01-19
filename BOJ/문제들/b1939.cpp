#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <cstring>
#include <stack>
#include <queue>
#include <limits.h>
#include <map>
#include <stdlib.h>

using namespace std;

typedef unsigned long long ull;
typedef long long ll;

int n,m,st,endd;
int tb1[100001];
int tb2[1001][1001];
int che2[1001][1001];
ull che1[100001];
string s[100001];

vector< pair<int,int> > a[10001];
bool visited[10001];

bool dfs(int idx, int limit){
	if(visited[idx]){
		return false;
	}
	visited[idx] = true;

	if(idx == endd) {
		return true;
	}

	for(int i=0;i<a[idx].size();++i){
		int next = a[idx][i].first;
		int cost = a[idx][i].second;
		if(cost >= limit){
			if(dfs(next, limit)){
				return true;
			}
		}
	}
	return false;
}

int main(void){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cin >> n >> m;
	for(int i=0;i<m;++i){
		int x,y,z;
		cin >> x >> y >> z;
		a[x].push_back(make_pair(y,z));
		a[y].push_back(make_pair(x,z));
	}
	cin >> st >> endd;
	int left, right;
	left = 1;
	right = 1000000000;
	int ans = 0;

	while(left <= right){
		// cout << "left : " << left << endl;
		// cout << "rt : " << right << endl;
		int mid = left + (right - left) / 2;
		memset(visited, false, sizeof(visited));
		if(dfs(st,mid)){	
			ans = mid;
			left = mid + 1;
		}
		else{
			right = mid - 1;
		}

	}
	cout << ans << endl;
	return 0;
}
