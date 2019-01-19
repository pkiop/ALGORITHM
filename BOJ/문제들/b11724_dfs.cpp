#include <iostream>
#include <vector>

using namespace std;

vector<int> a[1001];
bool ch[1001];

void dfs(int x){
	ch[x] = true;
	for(int i=0;i<a[x].size();++i){
		int temp = a[x][i];
		if(ch[temp]==false){
			dfs(temp);
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
			dfs(i);
			ans++;
		}
	}
	cout << ans;
	return 0;
}
