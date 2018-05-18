#include <iostream>
#include <algorithm>
#include <vector>
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

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int n, m;
	cin >> n >> m;
	vector<int> input(n+1);
	vector<int> input2(n + 1);
	for (int i = 1; i <= n; ++i) {
		cin >> input[i];
		input2[i] = -input[i];
	}

	RMQ myRMQ(input);
	RMQ myRMQ2(input2);
	int cnt = 1;
	int first_2 = 2;
	//for (int i = 1; i < myRMQ.rangeMin.size(); ++i) {
	//	
	//	cout << myRMQ.rangeMin[i] << ' ';
	//	cnt++; 
	//	if (cnt == first_2) {
	//		cout << endl;
	//		first_2 *= 2;
	//	}
	//}
	int a, b;
	
	for (int i = 0; i < m; ++i) {
		cin >> a >> b;
		cout << myRMQ.query(a, b) << ' ' << -myRMQ2.query(a,b) << '\n';
	}
	return 0;
}