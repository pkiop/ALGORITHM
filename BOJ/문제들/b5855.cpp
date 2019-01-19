#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

vector<int> adj[1001];
int visited[1001];
int charge[] = { 500,100,50,10,5,1 };
int main(void) {
	int n;
	cin >> n;
	n = 1000 - n;
	int cnt = 0;
	while (n != 0) {
		for (int i = 0; i < 6; ++i) {
			while (n >= charge[i]) {
				n -= charge[i];
				cnt++;
			}
		}
	}
	cout << cnt;
	return 0;
}