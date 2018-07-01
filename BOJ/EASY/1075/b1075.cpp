#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <cstring>
#include <string>

using namespace std;

int main(void) {
	int n, f;
	cin >> n >> f;
	n -= n % 10;
	n -= n % 100;
	while (1) {
		if (n%f == 0) {
			string temp = to_string(n);
			int len = temp.size();
			cout << temp[len - 2] << temp[len - 1] << endl;
			return 0;
		}
		n++;
	}
}