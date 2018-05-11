#include <iostream>
#include <limits.h>
#include <algorithm>
using namespace std;

typedef long long ll;

const ll Imax = 1000000000000000000ll;
int main(void)
{
	ll n,k;
	cin >> n >> k;
	ll left = 0;
	ll right = min(n*n ,1000000000ll);
	while(left <= right){
		ll mid = (left + right) / 2;
		ll cnt = 0;
		for(int i=1;i<=n;++i){
			cnt += min(mid/i,n);
		}
		if(cnt < k){
			left = mid + 1;
		}
		else{
			right = mid - 1;
		}
	}
	cout << left << endl;
	
	return 0;
}