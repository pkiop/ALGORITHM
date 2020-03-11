#include <iostream>

using namespace std;

bool ansarr[64];
int main(void) {
	int n;
	cin >> n;
	string a; int b;
	int A;
	bool ac, bc;
	bool t = true;
	for(int i=0;i<64;++i) {
		ansarr[i] = t;
		if((i+1)%8 == 0) {
			continue;
		}
		t = !t;
	}


	
	for(int i=0;i<n;++i) {
		cin >> a >> b;
		A = 8 * (a[1] - '0' - 1) + (a[0] - 'A') + 1;
		if(ansarr[A-1] == ansarr[b-1]){
			cout << "YES" << endl;
		}
		else {
			cout << "NO" << endl;
		}
	}
	return 0;
}
