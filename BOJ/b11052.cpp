#include <iostream>
#include <cstring>

using namespace std;

#define MAX(a,b) ((a)>(b))?(a):(b)

int d[10001];
int p[10001];

int main() {
	int t;
	cin >> t;
	for (int i = 1; i <= t; ++i) {
		cin >> p[i];
	}
	for (int i = 1; i <= t; ++i) {
		for (int j = 1; j <= i; ++j) {
			d[i] = MAX(d[i],d[i-j]+p[j]);
		}
	}
	cout << d[t];
	return 0;
}