#include <iostream>
#include <vector>
#include <algorithm>
#include <fstream>
#include <string>
#include <cstring>


using namespace std;

#define GO

int main(void) {

#ifdef GO
	freopen("input.txt", "r", stdin);
#endif
	int n;
	cin >> n;
	int ncheck = 0;
	for (int i = 666; i <= 100000000; ++i) {
		int temp = i;
		int cnt = 0;
		while (temp > 0) {
			if (temp % 10 == 6) {
				cnt++;
			}
			else {
				cnt = 0;
			}
			temp /= 10;
			if (cnt == 3) {
				ncheck++;
			}
		}
		if (ncheck == n) {
			cout << i << endl;
			return 0;
		}
	}
	
	return 0;
}