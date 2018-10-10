#include <iostream>
#include <vector>
#include <algorithm>
#include <fstream>
#include <string>
#include <cstring>
#include <map>

#define pii pair<int, int>
#define pli pair<long, int>
#define mii map<int, int>
#define msi map<string, int>

typedef unsigned long long ull;
typedef long long ll;

using namespace std;



#define GO
#define DEBUG


/*

5 21
-3 2 -4 -1 -5

*/


int main(void) {

#ifdef GO
	freopen("input.txt", "r", stdin);
#endif

	int n;
	cin >> n;
	if ((n - 2) % 3 != 0) {
		cout << 1 << ' ' << 1 << ' ' << n - 2;
	}
	else {
		cout << 2 << ' ' << 2 << ' ' << n - 4;
	}











#ifdef GO
	cout << "\nerase go\n";
#endif

	return 0;
}