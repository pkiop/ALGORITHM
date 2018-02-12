#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int a[51][51];
int b[51][51];
int n,m;

void p(int y,int x){
	for(int i=y;i<=y+2;++i){
		for(int j=x;j<=x+2;++j){
			a[i][j] = 1 - a[i][j];
		}
	}
}

int main(void){
	
	cin >> n >> m;

	for(int i=0;i<n;++i){
		for(int j=0;j<m;++j){
			scanf("%1d",&a[i][j]);
		}
	}

	for(int i=0;i<n;++i){
		for(int j=0;j<m;++j){
			scanf("%1d",&b[i][j]);
		}
	}
	int cnt = 0;
	for(int i=0;i<n-2;++i){
		for(int j=0;j<m-2;++j){
			if(a[i][j]!=b[i][j]){
				p(i,j);
				cnt++;
			}
		}
	}
	for(int i=0;i<n;++i){
		for(int j=0;j<m;++j){
			if(a[i][j]!=b[i][j]){
				cout << "-1\n";
				return 0;
			}
		}
	}
	cout << cnt << endl;
	return 0;
}