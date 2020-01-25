#include <iostream>
#include <algorithm>
using namespace std;

int main(void) {
	int n, m;
	cin >> n >> m;
	int a,b,c,d;
	int t1,t2;
	bool first = true;
	for(int i=0;i<n;++i) {
		for(int j=0;j<m;++j) {
			cin >> t1;
			if(t1 == 1){
				if(first) {
					first = false;
					a = i; b = j;
				}
				else {
					c = i; d = j;
				}
				
				
			}

		}
	}
	cout << abs(a - c) + abs(b - d) << endl;
	return 0;
}
