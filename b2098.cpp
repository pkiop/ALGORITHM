#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <cstring>
#include <stack>
#include <queue>
#include <limits.h>

using namespace std;

typedef unsigned long long ull;
typedef long long ll;

const int INF = 987987987;

int n;
int pivot;
int tb1[100001];
int tb2[16][16];
int che2[16][1<<16];
int che1[100001];

int go(int idx, int state){
	if((state & (1<<pivot)) && state != (1 << n) - 1) return INF; // state와 pivot이 중복되면서 state가 완전히 탐색한 상태가 아닐 때 INF
	if(state == (1<<n) - 1) return 0;
	int& ret = che2[idx][state];
	if(ret != -1) return ret;

	ret = INF;
	for(int i=0;i<n;++i){
		if(tb2[idx][i] > 0 && !(state&(1<<i))){
			ret = min(ret, go(i,state | (1<<i)) + tb2[idx][i]);
		}
	}
	return ret;
}

int main(void){
	cin >> n;
	for(int i=0;i<n;++i){
		for(int j=0;j<n;++j){
			cin >> tb2[i][j];
		}
	}
	int ans = INF;
	for(int i=0;i<n;++i){
		memset(che2,-1,sizeof(che2));
		pivot = i;
		ans = min(ans, go(i,0));
	}
	cout << ans << endl;
	return 0;
}