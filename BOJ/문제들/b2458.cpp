#include <iostream>

using namespace std;

int n,m;
bool table[501][501];

void init() {
	for(int i=1;i<=n;++i){
		for(int j=1;j<=n;++j) {
			if(i == j) {
				table[i][j] = true;
			}
		}
	}
}
	
void d_print_table() {
	for(int i=1;i<=n;++i) {
		for(int j=1;j<=n;++j) {
			cout << table[i][j] << ' ';
		}
		cout << '\n';
	}
}

int main(void) {
	cin >> n >> m;
	init();
	//d_print_table();

	int a,b;
	for(int i=0;i<m;++i) {
		cin >> a >> b;
		table[a][b] = true;
	}

	for(int k=1;k<=n;++k) {
		for(int i=1;i<=n;++i) {
			for(int j=1;j<=n;++j) {
				if(table[i][k] == true && table[k][j] == true) {
					table[i][j] = true;
				}
			}
		}
	}

	//d_print_table();


	int ans = 0;
	for(int x=1;x<=n;++x) {
		bool anspq = true;
		for(int y=1;y<=n;++y) {
			if(table[x][y] == false && table[y][x] == false) {
				anspq = false;
				break;
			}
		}
		if(anspq == true) {
			ans++;
		}
	}
	cout << ans << endl;

} 
