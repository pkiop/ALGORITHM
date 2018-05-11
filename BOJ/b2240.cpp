#include <iostream>
#include <cstring>
#include <algorithm>
#include <vector>

using namespace std;

int tb1[1001];
int cache[1001][1001][2];
int n, m;

int go(int idx,int tree,int changecnt) {
	if (idx >= n) {
		return 0;
	}
	if (changecnt > m) {
		return 0;
	}
	
	int& ret = cache[idx][changecnt][tree];
	if (ret != -1) {
		return ret;
	}
	int val = (tb1[idx] == tree ? 1 : 0);
	
	ret = max(go(idx + 1, tree, changecnt), go(idx + 1, 3 - tree, changecnt + 1)) + val;

	return ret;
}

int main(void) {
	memset(cache, -1, sizeof(cache));

	cin >> n >> m;

	for (int i = 1; i <= n; ++i) {
		cin >> tb1[i];
	}
	tb1[0] = 0; // i = 0부터 해서 이 코드를 넣지 않으면 시작하자마자 이동할 수 있는 경우를 생각해 주지 못한다. 
	cout << go(0, 1, 0) << endl;
	
	return 0;
	
}