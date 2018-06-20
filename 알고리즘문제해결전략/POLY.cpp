#include <iostream>
#include <cstring>

using namespace std;

const int mod = 10*1000*1000;

int cache[101][101];

int poly(int n,int first){
	//기저사례 n == first
	if(n == first){
		return 1;
	}

	int& ret = cache[n][first];
	if(ret != -1){
		return ret; 
	}

	ret = 0;
	for(int second=1;second<=n-first;++second){
		int add = second + first - 1;
		add *= poly(n - first, second);
		add %= mod;
		ret += add;
		ret %= mod;
	}
	return ret;
}

int main(void){
	int t;
	cin >> t;
	while(t--){
		memset(cache,-1,sizeof(cache));
		int k;
		cin >> k;
		long long ans = 0;
		for(int i=1;i<=k;++i){
			ans += poly(k,i)%mod;
		}
		cout << ans%mod << endl;
	}

	return 0;
}
