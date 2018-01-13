#include <iostream>
#include <vector>
#include <queue>

using namespace std;

vector<int> a[1001];
queue<int> q;
bool ch[1001];

void bfs(int x){
	ch[x] = true;
	q.push(x);
	while(!q.empty()){
		int temp = q.front();
		ch[temp] = true;
		q.pop();
		for(int i=0;i<a[temp].size();++i){
			int k = a[temp][i];
			if(ch[k]==false){

				q.push(k);
			}
		}
	}
}

int main(){
	int n, m;
	cin >> n >> m;
	for(int i=0;i<m;++i){
		int x,y;
		cin >> x >> y;
		a[x].push_back(y);
		a[y].push_back(x);
	}
	int ans=0;
	for(int i=1;i<=n;++i){
		if(ch[i]==false){
			bfs(i);
			ans++;
		}
	}
	cout << ans;
	return 0;
}
