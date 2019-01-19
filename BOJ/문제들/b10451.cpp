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
	int t;
	cin >> t;
	while(t--){
		int tt;
		cin >> tt;
		for(int i=1;i<=tt;++i){
			int k;
			cin >> k;
			a[i].push_back(k);
		}
		int cnt = 0;
		for(int i=1;i<=tt;++i){
			if(ch[i]==false){
				dfs(i);
				cnt++;
			}
		}
		cout << cnt << '\n';
		for(int i=0;i<1001;++i){
			a[i].clear();
			ch[i] = false;
		}
	}
	return 0;
}
