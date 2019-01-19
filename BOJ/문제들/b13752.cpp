#include <iostream>
#include <vector>
#include <algorithm>
#include <fstream>
#include <string>
#include <cstring>
#include <queue>


using namespace std;

/*

5 21
-3 2 -4 -1 -5

*/
#define GO

char arr[1001][1001];
int visited[1001][1001];
int dx[] = { 0,0,-1,1 };
int dy[] = { 1,-1,0,0 };



int main(void) {

#ifdef GO
	freopen("input.txt", "r", stdin);
#endif
	int t;
	cin >> t;
	int n;

	while (t--) {
		cin >> n;
		for (int i = 0; i < n; ++i) {
			cout << '=';
		}
		cout << '\n';
	}
	return 0;
}