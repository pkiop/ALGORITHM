#include <iostream>
#include <vector>
#include <queue>

using namespace std;

vector<int> a[20001];
int ch[20001];
bool check = false;

void dfs(int x,int c){
	ch[x] = c;
	for(int i=0;i<a[x].size();++i){
		int temp = a[x][i];
		if(ch[temp]==c){
			check = true;
			return;
		}
		if(ch[temp]==0){
			dfs(temp,3-c);
		}
	}
}

int main(){
	int t;
	cin >> t;
	while(t--){
		for(int i=0;i<20001;++i){
			a[i].clear();
			ch[i] = 0;
		}
		int n,m;
		cin >> n >> m;
		for(int i=0;i<m;++i){
			int x,y;
			cin >> x >> y;
			a[x].push_back(y);
			a[y].push_back(x);
		}
		for(int i=1;i<=n;++i){
			if(ch[i]==0){
				dfs(i,1);
			}
		}
		cout << ((check)?"NO":"YES") << '\n';
		check = false;
	}
	return 0;
}
