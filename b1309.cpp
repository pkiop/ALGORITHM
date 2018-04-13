#include <iostream>
#include <algorithm>
#include <cstring>
#include <limits.h>
#include <stack>

using namespace std;

typedef long long ll;

ll stb[10001]; // single table
ll sche[100001]; // single cache
int tb[1001][1001];
int cache[1001][1001];
int n,m;
const int mod = 9901;

int main(void) {
	
	cin >> n;
	sche[0] = 1;
	sche[1] = 3;
	for (int i = 2; i <= n; ++i) {
		
		int wow = sche[i - 1] - sche[i - 2];
		if (wow < 0) {
			wow += mod;
		}
		
		
		sche[i] = (sche[i-2]*3)%mod  + (2*(wow))%mod;
	}
	cout << sche[n]%mod;
	
	
	return 0;
}