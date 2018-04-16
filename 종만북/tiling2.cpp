#include <iostream>
#include <cstring>

using namespace std;
const int mod = 1000000007;
int cache[1001];
int go(int n){
	int& ret = cache[n];
	if(ret != -1){
		return ret;
	}

	if(n<=1){
		return 1;
	}
	
	ret = go(n-1)%mod +go(n-2)%mod;
	return ret%mod;
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