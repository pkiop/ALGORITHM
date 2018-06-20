#include <iostream>
#include <cstring>
using namespace std;

const int mod = 1000000007;

int cache[1001];

int tiling(int n){
	if(n<=1){
		return 1;
	}
	int& ret = cache[n];
	if(ret != -1){
		return ret;
	}
	
	ret = (tiling(n-1)%mod + tiling(n-2)%mod)%mod;
	return ret;
}

int go(int n){
	if(n % 2 == 1)
		return (tiling(n) - tiling(n/2) + mod)%mod;
	int ret = tiling(n);
	ret = (ret - tiling(n/2)+mod)%mod;
	ret = (ret - tiling(n/2-1)+mod)%mod;
	return ret;
}

int main(void)
{

	int t;
	cin >> t;
	while(t--){
		memset(cache,-1,sizeof(cache));
		int n;
		cin >> n;
		
		cout << go(n) << endl;
	}
	return 0;
}