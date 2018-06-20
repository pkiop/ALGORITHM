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

int cache2[1001];
int asytiling(int n){
	if(n<=2){
		return 0;
	}

	int& ret = cache2[n];
	if(ret != -1){
		return ret;
	}

	ret = asytiling(n-2) % mod; // a
	ret = (ret + asytiling(n-4)) % mod; // b
	ret = (ret + tiling(n-3)) % mod; // c
	ret = (ret + tiling(n-3)) % mod; // d
	return ret;

}

int go(int n){ // 대칭 타일 구하는 함수로 구하는 법
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
		memset(cache2,-1,sizeof(cache2));
		int n;
		cin >> n;
		
		cout << asytiling(n) << endl;
	}
	return 0;
}