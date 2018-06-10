#include <iostream>
#include <cstring>

using namespace std;

int tb2[1001][1001];
int cache2[1001][1001];
int n;

int go(int x,int y){
	if(x == n){
		return 0;
	}

	int& ret = cache2[x][y];
	if(ret != -1){
		return ret;
	}
	ret = 0;
	ret = tb2[x][y] + max(go(x+1,y), go(x+1,y+1));
	return ret;
}

int main(void)
{
	int t;
	cin >> t;
	while(t--){
		memset(tb2,0,sizeof(tb2));
		memset(cache2,-1,sizeof(cache2));
		
		cin >> n;
		for(int i=0;i<n;++i){
			for(int j=0;j<=i;++j){
				cin >> tb2[i][j];
			}
		}
		cout << go(0,0) << endl;
	}
}