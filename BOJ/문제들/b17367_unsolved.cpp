#include <iostream>
#include <math.h>
#include <fstream>
#include <string>
#include <cstring>

using namespace std;

#define GO 
int main(void) {
#ifdef GO
	freopen("input.txt", "r", stdin);
#endif
	double a, b;
	cin >> a;
	double answer = 0;
	int debug_num = 0;
	for (int i = 1; i <= 6; ++i) {
		answer += (1 / pow(6, 3) * (10000 + 1000 * double(i)));
		debug_num += 1;
	}
	for (int i = 1; i <= 6; ++i) {
		answer += ((1 / 6) * (1 / 6) * (5 / 6) * 3) * (1000 + 100 * double(i));
		debug_num += 1 * 1 * 5 * 3;
	}
	for (int i = 3; i <= 6; ++i) {
		answer += ((1 / 6) * (double(i-1) / 6) * (double(i-2) / 6) * 3) * 100 * double(i);
		debug_num += 1 * (i-1) * (i-2) * 3;
	}

	cout.precision(9);
	cout << debug_num << endl;
	cout << answer;

	
	return 0;
}
