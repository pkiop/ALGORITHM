#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

//펜윅 트리의 구현, 가상의 배열 A[]의 부분합을
//빠르게 구현할 수 있도록 한다. 초기화시에는 A[]의 
//원소가 전부 0이라고 생각한다.

struct FenwickTree {
	vector<int> tree;
	FenwickTree(int n) : tree(n+1) {}

	int sum(int pos) {
		++pos;
		int ret = 0;
		while (pos > 0) {
			ret += tree[pos];
			pos &= (pos - 1);
		}
		return ret;
	}
	
	void add(int pos, int val) {
		++pos;
		while (pos < tree.size()) {
			tree[pos] += val;
			pos += (pos & -pos);
		}
	}
};

long long countMoves(const vector<int>& A) {
	FenwickTree tree(1000000);
	long long ret = 0;
	for (int i = 0; i < A.size(); ++i) {
		ret += tree.sum(999999) - tree.sum(A[i]);
		tree.add(A[i], 1);
	}
	return ret;
}

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int t;
	cin >> t;
	while (t--) {
		int n;
		cin >> n;
		vector<int> arr(n);
		for (int i = 0; i < n; ++i) {
			cin >> arr[i];
		}
		cout << countMoves(arr) << '\n';
	}
	return 0;
}