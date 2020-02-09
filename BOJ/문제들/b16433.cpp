#include <iostream>

using namespace std;

int main(void) {
	int a,b,c;
	cin >> a >> b >> c;
	bool xev = c%2 == 0;
	bool yev = b%2 == 0;
	if(xev == yev) {
		bool vfirst = true;
		for(int y=1;y<=a;++y) {
			for(int x=1;x<=a;++x) {
				if(vfirst) {
					if(x % 2 == 1) {
						cout << 'v';
					}
					else {
						cout << '.';
					}
				}
				else {
					if(x % 2 == 0) {
						cout << 'v';
					}
					else {
						cout << '.';
					}	
				}
			}
			cout << endl;
			vfirst = !vfirst;
		}
	}
	else {
		bool vfirst = false;
		for(int y=1;y<=a;++y) {
			for(int x=1;x<=a;++x) {
				if(vfirst) {
					if(x % 2 == 1) {
						cout << 'v';
					}
					else {
						cout << '.';
					}
				}
				else {
					if(x % 2 == 0) {
						cout << 'v';
					}
					else {
						cout << '.';
					}	
				}
			}
			cout << endl;
			vfirst = !vfirst;
		}
	}
}
