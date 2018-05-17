#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

//펜윅 트리의 구현, 가상의 배열 A[]의 부분합을
//빠르게 구현할 수 있도록 한다. 초기화시에는 A[]의 
//원소가 전부 0이라고 생각한다.
typedef long long ll;

struct FenwickTree {
	vector<ll> tree;
	FenwickTree(ll n) : tree(n+1) {}

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
	
	
	ll n,m,k;
	cin >> n >> m >> k;
	FenwickTree tree(1000001);
	vector<ll> arr(1000001);
	ll in;
	for (int i = 1; i <= n; ++i) {
		cin >> in;
		tree.add(i-1, in);
		arr[i] = in;
	}

	for (int i = 0; i < m + k; ++i) {
		ll a, b, c;
		cin >> a >> b >> c;
		if (a == 1) {
			tree.add(b-1, c - arr[b]);
			arr[b] = c;
		}
		else {
			cout << tree.sum(c-1) - tree.sum(b-2) << '\n';
		}
	}
	
	
	return 0;
}