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

int n;

int ans[3];
int tb2[3001][3001];

bool same(int x,int y,int k){
	for(int i=x;i<x+k;++i){
		for(int j=y;j<y+k;++j){
			if(tb2[i][j]!=tb2[x][y]){
				return false;
			}
		}
	}
	return true;
}

void go(int x,int y,int k){

	if(same(x,y,k)){
		ans[tb2[x][y]+1] += 1;
		return;
	}

	for(int i=0;i<3;++i){
		for(int j=0;j<3;++j){
			go(x + i*(k/3), y + j*(k/3),k/3);
		}
	}
}

int main(void)
{
	int n;
	cin >> n;
	for(int i=0;i<n;++i){
		for(int j=0;j<n;++j){
			cin >> tb2[i][j];
		}
	}

	go(0,0,n);

	for(int i=0;i<3;++i){
		cout << ans[i] <<endl;
	}


}