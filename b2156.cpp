#include <iostream>
#include <cstring>
using namespace std;

#define MAX(a,b) (((a)>(b))?(a):(b))

int podo[10001];
int d[10001][3];
int main() {
	int t;
	cin >> t;
	for (int i = 1; i <= t; ++i) {
		cin >> podo[i];
	}
	d[1][0] = 0;
	d[1][1] = podo[1];
	d[1][2] = 0;
	
	for (int i = 2; i <= t; ++i) {
		d[i][0] = MAX(d[i - 1][0], MAX(d[i - 1][1], d[i - 1][2]));
		d[i][1] = d[i-1][0]+podo[i];
		d[i][2] = d[i - 1][1] + podo[i];
	}
	int ans = 0;

	
	cout << MAX(d[t][0], MAX(d[t][1], d[t][2]));

	
	
	return 0;
}