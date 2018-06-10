#include <iostream>
#include <vector>
#include <algorithm>
#include <limits>

using namespace std;

struct RMQ {
	int n;
	vector<int> rangeMin;

	RMQ(const vector<int>& arr) {
		n = arr.size();
		rangeMin.resize(4 * n);
		init(arr, 0, n - 1, 1);
	}
	int init(const vector<int>& arr, int left, int right, int node) {
		if (left == right) {
			return rangeMin[node] = arr[left];
		}
		int mid = (left + right) / 2;
		int leftMin = init(arr, left, mid, 2 * node);
		int rightMin = init(arr, mid + 1, right, 2 * node + 1);
		return rangeMin[node] = min(leftMin, rightMin);
	}
	int query(int left, int right, int node, int nodeLeft, int nodeRight) {
		if (right < nodeLeft || left > nodeRight) {
			return INT32_MAX;
		}
		if (left <= nodeLeft && right >= nodeRight) {
			return rangeMin[node];
		}
		int mid = (nodeLeft + nodeRight) / 2;
		int leftbaby = query(left, right, node * 2, nodeLeft, mid);
		int rightbaby = query(left, right, node * 2 + 1, mid + 1, nodeRight);
		return min(leftbaby, rightbaby);
	}
	int query(int left, int right) {
		return query(left, right, 1, 0, n - 1);
	}
	int update(int index, int newValue, int node, int nodeLeft, int nodeRight) {
		//index가 범위와 관계없을 경우
		if (index < nodeLeft || index > nodeRight) {
			return rangeMin[node];
		}
		//리프까지 내려온 경우
		if (nodeLeft == nodeRight) {
			return rangeMin[node] = newValue;
		}
		int mid = (nodeLeft + nodeRight) / 2;
		int a = update(index, newValue, 2 * node, nodeLeft, mid);
		int b = update(index, newValue, 2 * node + 1, mid + 1, nodeRight);
		return rangeMin[node] = min(a, b);
	}
	int update(int index, int newValue) {
		return update(index, newValue, 1, 0, n - 1);
	}
};
// 최소 공통 조상 문제를 구간 최소 질의 문제로 바꾸기

const int MAX_N = 100020;
int n;
vector<int> child[MAX_N];
//트리의 번호와 일련번호 사이의 대응 관계

int no2serial[MAX_N], serial2no[MAX_N];
//각 노드가 trip에 처음 등장하는 위치, 그리고 각 노드의 깊이
int locInTrip[MAX_N], depth[MAX_N];
//다음 일련번호
int nextSerial;
// 깊이가 d인 노드 here 이하를 전위탐색한다.

void traverse(int here, int d, vector<int>& trip) {
	// traverse가 처음 방문하자마자 일련번호를 부여한다.
	// 이렇게 하면 항상 부모는 자손보다 작은 일련번호를 갖게 된다. 
	no2serial[here] = nextSerial;
	serial2no[nextSerial] = here;
	++nextSerial;
	//깊이 계산
	depth[here] = d;
	//trip에 현재 노드의 일련번호를 추가한다. 
	locInTrip[here] = trip.size();
	trip.push_back(no2serial[here]);
	//모든 자식 노드를 방문

	for (int i = 0; i < child[here].size(); ++i) {
		traverse(child[here][i], d + 1, trip);
		//자식 노드를 방문하고 현재 노드로 돌아올 때마다 다시 추가하기
		trip.push_back(no2serial[here]);
	}
}


//트리를 순회하며 각종 필요한 정보를 계산하고,
//RMQ 구간트리를 만들어 반환한다.
RMQ* prepareRMQ() {
	nextSerial = 0;
	//순회 과정에서 만나는 노드들의 일련번호를 담는다. 
	vector<int> trip;
	traverse(0, 0, trip);
	return new RMQ(trip);
}

int distance(RMQ* rmq, int u, int v) {
	//trip[] 배열에서 u와 v의 첫 출현 위치를 찾는다.
	int lu = locInTrip[u], lv = locInTrip[v];
	if (lu > lv) swap(lu, lv);
	//rmq는 u와 v의 최소 공통 조상의 일련번호를 반환한다.
	int lca = serial2no[rmq->query(lu, lv)];
	return depth[u] + depth[v] - 2 * depth[lca];
}

int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int t;
	cin >> t;
	int a, b;
	int in1,in2;
	while (t--) {
		for (int i = 0; i < MAX_N; ++i) {
			child[i].clear();
		}
		cin >> a >> b;
		for (int i = 1; i < a; ++i) {
			cin >> in1;
			child[in1].push_back(i);
		}
		RMQ* myRMQ = prepareRMQ();
		
		for (int i = 0; i < b; ++i) {
			cin >> in1 >> in2;
			
			cout << distance(myRMQ, in1, in2) << '\n';
			
		}
		delete myRMQ;
	}
	
	return 0;
}
