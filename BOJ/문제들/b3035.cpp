#include <iostream>
#include <string>

using namespace std;

char arr[1001][1001];
int main(void) {
	int r, c, zr, zc;
	cin >> r >> c >> zr >> zc;
	string s;
	for(int y=0;y<r;++y) {
		cin >> s;
		for(int x=0;x<c;++x) {
			arr[x][y] = s[x];
		}
	}

	for(int y=0;y<r;++y){
		for(int rep=0;rep<zr;++rep) {
			for(int x=0;x<c;++x) {
				for(int rep2=0;rep2<zc;++rep2){
					cout << arr[x][y];
				}
			}
			cout << endl;
		}
	}
}
