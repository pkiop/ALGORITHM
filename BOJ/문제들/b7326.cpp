#include <iostream>

using namespace std;

int main(void) {
	int n;
	cin >> n;
	int x,y;
	for(int i=0;i<n;++i) {
		cin >> x >> y;
		if(x == y || x == y + 2) {
			if(x == y) {
				if(y % 2 == 0) {
					cout << y * 2 << endl;
				}
				else{
					cout << (y + 1) * 2 - 3 << endl;
				}
			}
			else {
				if(y % 2 == 0) {
					cout << y * 2 + 2 << endl;
				}
				else {
					cout << (y + 1) * 2 + 2 - 3 << endl;
				}
			}
		}
		else {
			cout << "No Number" << endl;
		}
	}
	return 0;
}
