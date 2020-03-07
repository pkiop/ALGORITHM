#include <iostream>

using namespace std;

int main(void) {
	int n;
	cin >> n;
	int a, b;
	int axis = 0;
	int q1 = 0;
	int q2 = 0;
	int q3 = 0;
	int q4 = 0;
	for(int i=0;i<n;++i) {
		cin >> a >> b;
		if(a == 0 || b == 0) {
			axis++;	
		}
		else if (a > 0 && b > 0) {
			q1++;
		}
		else if (a > 0 && b < 0) {
			q4++;
		}
		else if (a < 0 && b > 0) {
			q2++;
		}
		else if (a < 0 && b < 0) {
			q3++;
		}
	}
	cout << "Q1: " << q1 << endl;
	cout << "Q2: " << q2 << endl;
	cout << "Q3: " << q3 << endl;
	cout << "Q4: " << q4 << endl;
	cout << "AXIS: " << axis << endl;
	return 0;
}
