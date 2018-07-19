#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
using namespace std;


int main(void) {
	
	string s;
	cin >> s;
	int n = s.length();

	int r = 0;
	vector<int> fin(3, -1);
	fin[0] = 0;

	vector<int> z(n + 1);
	for (int i = 1; i <= n; i++) {
		r = (r + s[i - 1] - '0') % 3;
		z[i] = z[i - 1];
		if (fin[r] != -1)
			z[i] = max(z[i], z[fin[r]] + 1);
		fin[r] = i;
	}

	cout << z[n] << endl;

	return 0;
}