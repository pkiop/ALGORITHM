#include <iostream>
#include <vector>
#include <algorithm>
#include <map>

using namespace std;

//펜윅 트리의 구현, 가상의 배열 A[]의 부분합을
//빠르게 구현할 수 있도록 한다. 초기화시에는 A[]의 
//원소가 전부 0이라고 생각한다.
typedef long long ll;

struct FenwickTree {
	vector<ll> tree;
	FenwickTree(ll n) : tree(n + 1) {}

	ll sum(ll pos) {
		++pos;
		ll ret = 0;
		while (pos > 0) {
			ret += tree[pos];
			pos &= (pos - 1);
		}
		return ret;
	}

	void add(ll pos, ll val) {
		++pos;
		while (pos < tree.size()) {
			tree[pos] += val;
			pos += (pos & -pos);
		}
	}
};

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	ll n, m, k;
	cin >> n;
	vector<ll> arr1(n);
	map<ll, ll> B;
	for (int i = 0; i < n; ++i) {
		cin >> arr1[i];
	}
	ll temp;
	for (int i = 0; i < n; ++i) {
		cin >> temp;
		B[temp] = i;
	}

	FenwickTree myTree(1000001);

	ll cnt = 0;
	for (int i = 0; i < n; ++i) {
		int valA = arr1[i];
		int idxB = B[valA];
		cnt += myTree.sum(n) - myTree.sum(idxB);
		myTree.add(idxB, 1);
	}

	cout << cnt << endl;
	
	return 0;
}