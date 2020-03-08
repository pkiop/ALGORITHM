#include <iostream>

using namespace std;

int main(void) {
	int n;
	cin >> n;
	if(n % 10 > 0) {
		cout << -1;
		return 0;
	}
	int t = 0;
	while(n >= 300) {
		n-=300;
		t++;
	}
	int s = 0;
	while(n >= 60) {
		n-=60;
		s++;
	}
	int e = 0;
	while(n >= 10) {
		n -= 10;
		e++;
	}
	cout << t << ' ' << s << ' ' << e << endl;

}
