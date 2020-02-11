#include <iostream>
#include <string>

using namespace std;

int main(void) {
	int n;
	cin >> n;
	int A = 1, B = 0;
	int ta, tb; 
	for(int i=0;i<n;++i) {
		ta = B;
		tb = A + B;
		A = ta;
		B = tb;
	}
	cout << A << ' ' << B << endl;
}
