#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <cstring>
#include <stack>
#include <queue>
#include <limits.h>

using namespace std;

typedef long long ull;

int n;
int tb1[111];
ull che1[110][21];

ull go(int idx, int sum){
	if(idx == n-1 && sum == tb1[idx]){
		return 1;
	}
	else if(idx == n-1){
		return 0;
	}
	if(sum > 20){
		return 0;
	}
	if(sum < 0){
		return 0;
	}

	ull& ret = che1[idx][sum];
	if(ret != -1){
		return ret;
	}
	ret = 0;
	ret = go(idx+1,sum+tb1[idx]) + go(idx+1,sum-tb1[idx]);
	return ret;
}

int main(void){
	memset(che1,-1,sizeof(che1));
	cin >> n;
	for(int i=0;i<n;++i){
		cin >> tb1[i];
	}
	cout << go(1,tb1[0]) << endl;
	
	return 0;
}
