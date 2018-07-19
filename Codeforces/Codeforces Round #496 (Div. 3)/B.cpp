#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
using namespace std;

int main(void) {
	string a, b;
	cin >> a >> b;
	int lena = a.size()-1;
	int lenb = b.size()-1;

	while (a[lena] == b[lenb]) {
		lena--;
		lenb--;
		if (lena < 0 || lenb < 0) {	
			break;
		}
	}
	int ans = lena + 1 + lenb + 1;
	cout << ans << endl;

	return 0;
}