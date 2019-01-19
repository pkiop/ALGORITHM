#include <iostream>
#include <queue>
#include <functional>

using namespace std;

int main(void) {
	priority_queue<int, vector<int>, greater<int> > pq;
	int n;
	cin >> n;
	int k;
	for (int i = 0; i < n; ++i) {
		cin >> k;
		if (k != 0) {
			pq.push(k);
		}
		else {
			if (!pq.empty()) {
				cout << pq.top() << endl;
				pq.pop();
			}
			else {
				cout << 0 << endl;
			}
		}
	}
	
	return 0;
}