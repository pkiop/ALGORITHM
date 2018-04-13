#include <iostream>

using namespace std;

enum cnta {
	noc;// don't go
	mgo;// must go
	alc;// aleady cnt
}

int tb2[8][8];
int dx[] = {0,0,1,-1};
int dy[] = {1,-1,0,0};
int n = 8;

int go(int i,int j){
	if(tb2[i][j] == alc){
		return 0;
	}

	int ret = 0;
	for(int k=0;k<4;++k){
		int nx = i+dx[k];
		int ny = j+dx[k];
		if(0<= nx && nx <= n && 0 <= ny && ny <= n){
			cnt += go(nx,ny);
		}
	}
	return cnt; 
}
int main(void){
	cout << "do" << endl;
	for(int i=0;i<8;++i){
		for(int j=0;j<8;++j){
			cin >> tb2[i][j];
		}
	}
	int cnt = 0;

	for(int i=0;i<8;++i){
		for(int j=0;j<8;++j){
			cnt += go(i,j);
		}
	}

	cout << cnt << endl;
	return 0;
}