#include <iostream>
#include <algorithm>
#include <vector>
#include <cstring>

using namespace std;

int tb[2001];
int cache[2001][2001];

int go(int a,int b){
	if(b-a<1){
		return 1;
	}
	if(cache[a][b]!=-1){
		return cache[a][b];
	}

	int& ret = cache[a][b] = 0;
	if(tb[a] == tb[b]){
		ret = go(a+1,b-1);
	}
	else{
		ret = 0;
	}
	return ret;
}




int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	memset(cache,-1,sizeof(cache));
	int n;
	cin >> n;
	for(int i=0;i<n;++i){
		cin >> tb[i];
	}
	int t;
	cin >> t;
	while(t--){
		int a,b;
		cin >> a >> b;
		cout << go(a-1,b-1) << '\n';
	}
	return 0;
}