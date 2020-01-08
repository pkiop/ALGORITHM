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
	int n;
	cin >> n; 
	int answer = 1;
	int bias = 1;

	int cnt = 0;
	n--;
	while (n--) {
		if (cnt == 4) {
			cnt = 0;
			bias *= -1;
		}
		cnt++;
		answer = answer + bias;
	};
	cout << answer << endl;
	
	return 0;
}
