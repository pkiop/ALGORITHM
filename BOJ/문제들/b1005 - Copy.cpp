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
	cin >> a >> b;
	double M = (b - a) / 400.0;
	cout.precision(9);
	cout << 1 / (1 + pow(10, M));
	return 0;
}
