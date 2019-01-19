#include <iostream>
#include <queue>
#include <stack>

using namespace std;

int main() {
	int a, b;
	int m;
	cin >> a >> b >> m;
	int sum = 0;
	while (m--) {
		int k;
		cin >> k;
		
		int mul=1;
		for (int i = 0; i < m; ++i) {
			mul *= a;
		}
		
		sum += k * mul;
	}
	
	stack<int> q;
	while (sum / b != 0) {
		q.push(sum % b);
		sum /= b;
	}
	if (sum != 0) {
		q.push(sum);
	}
	while (!q.empty()) {
		cout << q.top() << ' ';
		q.pop();
	}
	return 0;
}