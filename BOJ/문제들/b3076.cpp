#include <iostream>

using namespace std;

int main(void) {
	int r, c, a, b;
	cin >> r >> c >> a >> b;
	bool tap = false;
	int tap_cnt = 0;
	for(int i=0;i<r;++i) {
		for(int l=0;l<a;++l) {
			for(int j=0;j<c;++j) {
				for(int k=0;k<b;++k) {
					if(tap == false){
						cout << 'X';
					}
					else {
						cout << '.';
					}
				}
				if(tap) {
					tap_cnt++;
					tap = false;
				}
				else {
					tap_cnt++;
					tap = true;
				}
			}
			if(c % 2 == 0) {
				if(tap) {
					tap = false;
				}
				else {
					tap = true;
				}
			}
			if(tap_cnt == c * a) {
				tap_cnt = 0;

			}
			else {
				if(tap) {
					tap = false;
				}
				else {
					tap = true;
				}
			}
			cout << endl;
		}
	}
}
