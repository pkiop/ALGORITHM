#include <iostream>
#include <vector>
#include <limits.h>

using namespace std;

typedef long long ll;

ll n,k;
int main(void)
{
	cin >> n >> k;
	vector<ll> tb1(n);
	for(int i=0;i<n;++i){
		cin >> tb1[i]; 
	}
	ll left = 0;
	ll right = 1000000000000000000LL;
	ll mid;
	while(left<=right){
		mid = (left + right) / 2;
		ll sum = 0;
		for(int i=0;i<n;++i){
			sum += mid / tb1[i]; 
		}
		if(sum >= k){
			right = mid - 1;
		}
		else{
			left = mid + 1;
		}
	}
	cout << left << endl;
	return 0;
}