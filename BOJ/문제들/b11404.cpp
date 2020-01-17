#include <iostream>
#include <vector>

using namespace std;

#define INF 99999999

int n;
int m;
int table[101][101];

void init() {
	for(int i=1;i<=n;++i) {
		for(int j=1;j<=n;++j) {
			if(i == j) {
				table[i][j] = 0;
			}
			else{	
				table[i][j] = INF;
			}
		}

	}
}

void ans_print() {
	for(int i=1;i<=n;++i) {
		for(int j=1;j<=n;++j) {
			if(table[i][j] == INF) {
				cout << 0 << ' ';
			}
			else {
				cout << table[i][j] << ' ';
			}
		}
		cout << '\n';
	}
}

int main(void) {
	cin >> n >> m;
	init();
	int a, b, c;
	for(int i=0; i<m; ++i) {
		cin >> a >> b >> c;
		if(table[a][b] != INF) {
			table[a][b] = (c > table[a][b] ? table[a][b] : c) ;
		}
		else{
			table[a][b] = c;
		}
	}

	for(int k=1;k<=n;++k){
		for(int i=1;i<=n;++i){
			for(int j=1;j<=n;++j) {
				if(table[i][k] + table[k][j] < table[i][j]) {
					table[i][j] = table[i][k] + table[k][j];
				}
			}
		}
	}


	ans_print();
}
