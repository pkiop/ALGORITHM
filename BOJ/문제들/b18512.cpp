#include <iostream>

using namespace std;

int main(void) {
	int a,b,c,d;
	cin >> a >> b >> c >> d;
	if(a == b && (c % a != d % a)) {
		cout << -1;
		return 0;
	}

	long long temp1 = c;
	long long temp2 = d;
	int cnt = 0;
	while(temp1 != temp2) {
		cnt++;
		if(cnt >= 1001) {
			cout << -1 << endl;
			return 0;
		}
		if(temp1 < temp2) {
			if((temp2 - temp1) >= a) {
				temp1 += ((temp2 - temp1) / a) * a;
			}
			else {
				temp1 += a;
			}
		}
		else {
			if((temp1 - temp2) >= b) {
				temp2 += ((temp1 - temp2) / b) * b;
			}
			else {
				temp2 += b;
			}
		}
	}
	cout << temp1;
	return 0;
}
