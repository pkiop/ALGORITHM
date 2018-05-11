#include <iostream>

using namespace std;

int parent[1000001];

int Find(int x) {
	if (parent[x] == x) // parent[x] == x 란 뜻은 루트라는 뜻
		return x;
	else {
		return parent[x] = Find(parent[x]); // 예외는 없다. 처음에 다 자기자신을 루트로 만들기 때문에 언젠가 루트를 리턴
	}
}

void Union(int x,int y) { // x에다가 y를 붙인다. 
	x = Find(x);
	y = Find(y);
	if (x != y) {
		parent[y] = x;
	}
}

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	int pc_cnt;
	cin >> pc_cnt;
	int n;
	cin >> n;
	for (int i = 1; i <= pc_cnt; ++i) {
		parent[i] = i;
	}
	int a, b;

	for (int i = 0; i < n; ++i) {
		cin >> a >> b;
		Union(a, b);
	}

	int cnt = 0;
	for (int i = 2; i <= pc_cnt; ++i) {
		if (Find(i) == Find(1)) {
			cnt++;
		}
	}
	cout << cnt << endl;
	return 0;
	
}