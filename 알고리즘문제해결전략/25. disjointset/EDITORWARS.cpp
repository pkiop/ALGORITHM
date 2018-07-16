#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
using namespace std;
int n;
struct BipartiteUnionFind {
	//parent[i] = i의 부모노드, 루트라면 i
	//rank[i] = i 가 루트인 경우, i를 루트로 하는 트리의 랭크
	//enemy[i] = i가 루트인 경우, 해당 집합과 적대 관계인 집합의 루트의 번호. (없으면 -1)
	//size[i] = i가 루트인 경우, 해당 집합의 크기
	vector<int> parent, rank, enemy, size;
	BipartiteUnionFind(int n) : parent(n), rank(n, 0), enemy(n, -1), size(n, 1) {
		for (int i = 0; i < n; ++i) parent[i] = i;
	}

	int find(int u) {
		if (parent[u] == u) return u;
		return parent[u] = find(parent[u]);
	}

	int merge(int u, int v) {
		//u나 v가 공집합인경우 나머지 하나를 반환한다.
		if (u == -1 || v == -1) return max(u, v);
		u = find(u); v = find(v);
		// 이미 둘이 같은 트리에 속한 경우
		if (u == v) return u;
		if (rank[u] > rank[v]) swap(u, v);
		//이제 항상 rank[v]가 더 크므로 u를 v의 자식으로 넣는다.
		if (rank[u] == rank[v]) rank[v]++;
		parent[u] = v;
		size[v] += size[u];
		return v;
	}

	bool dis(int u, int v) {
		//우선 루트를 찾는다.
		u = find(u); v = find(v);
		// 같은 집합에 있으면 모순
		if (u == v) return false;
		//적의 적은 나의 동지
		int a = merge(u, enemy[v]), b = merge(v, enemy[u]);
		enemy[a] = b; enemy[b] = a;
		return true;
	}

	bool ack(int u, int v) {
		u = find(u); v = find(v);
		if (enemy[u] == v) return false;
		int a = merge(u, v), b = merge(enemy[u], enemy[v]);
		enemy[a] = b;
		if (b != -1) enemy[b] = a;
		return true;
	}
};

int maxParty(const BipartiteUnionFind& buf) {
	int ret = 0;
	for (int node = 0; node < n; ++node) {
		if (buf.parent[node] == node) {
			int enemy = buf.enemy[node];
			//같은 모임 쌍을 두 번 세지 않기 위해, enemy < node 인 경우만 센다.
			//enemy == -1 인 경우도 정확히 한 번씩 세게 된다.
			if (enemy > node) continue;
			int mySize = buf.size[node];
			int enemySize = (enemy == -1 ? 0 : buf.size[enemy]);
			// 두 집합 중 큰 집합을 더한다.
			ret += max(mySize, enemySize);
		}
	}
	return ret;
}

int main(void) {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);
	int t;
	cin >> t;
	while (t--) {
		int b;
		cin >> n >> b;

		int k,l;

		BipartiteUnionFind temp(n);
		bool ans = false;
		int cc;
		for (int i = 0; i < b; ++i) {
			string tem;
			cin >> tem;
			cin >> k >> l;
			if (tem[0] == 'A') {
				if (temp.ack(k, l) == false && ans == false)
				{
					ans = true;
					cc = i + 1;
				}
			}
			else {
				if (temp.dis(k, l) == false && ans == false) {
					ans = true;
					cc = i + 1;
				}
			}
		}
		if (ans == true) {
			cout << "CONTRADICTION AT " << cc << endl;
		}
		else {
			cout << "MAX PARTY SIZE IS " << maxParty(temp) << endl;
		}
	}
	return 0;
}