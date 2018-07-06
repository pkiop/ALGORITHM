#include <iostream>
#include <algorithm>
#include <queue>
#include <string>
#include <cstring>

using namespace std;


int go(int x) {
	if (x == 1) {
		return 1;
	}
	if (x == 2) {
		return 2;
	}
	if (x == 3) {
		return 4;
	}
	return go(x - 1) + go(x - 2) + go(x - 3);
}


int main(void) {
	int n;
	cin >> n;
	int temp;
	for (int i = 0; i < n; ++i) {
		cin >> temp;
		cout << go(temp) << endl;
	}
	return 0;
}