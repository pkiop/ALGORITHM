#include <iostream>
#include <string>
#include <stack>
using namespace std;

int d[101];

int main() {
	d[2]=d[3]=d[1] = 1;
	d[4] = d[5] = 2;
	
	for (int i = 6; i < 101; ++i) {
		d[i] = d[i - 1] + d[i - 5];
	}
	int t;
	cin >> t;
	while (t--) {
		int k;
		cin >> k;
		cout << d[k] << '\n';
	}

		
	return 0;


}