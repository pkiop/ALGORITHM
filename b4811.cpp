#include <iostream>
#include <cstring>
using namespace std;

int n;
long long cache[32][32];
long long go(long long wcnt,long long hcnt){
	if(cache[wcnt][hcnt] != -1){
		return cache[wcnt][hcnt];
	}
	long long &ret = cache[wcnt][hcnt];
	if(wcnt < hcnt){
		ret = 0;
		return ret;
	}
	if(wcnt > n){
		ret = 0;
		return ret;
	}
	if(hcnt > n){
		ret = 0;
		return ret;
	}
	if(wcnt + hcnt >= n*2){
		return 1;
	}
	ret = go(wcnt + 1,hcnt) + go(wcnt, hcnt + 1);
	return ret;
}

int main(void)
{
	long long hcnt=0,wcnt=0;
	while(cin >> n && n != 0){
		memset(cache,-1,sizeof(cache));
		cout << go(wcnt,hcnt) << endl;
	}
}