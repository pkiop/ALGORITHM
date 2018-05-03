#include <iostream>
#include <queue>
#include <algorithm>

using namespace std;

void printqueue(queue<int> q) {
	while (!q.empty()) {
		cout << q.front() << endl;
		q.pop();
	}
}

int main(void)
{
	int t;
	cin >> t;
	while (t--) {
		queue<int> q;
		int a, b;
		cin >> a >> b;
		for (int i = 1; i <= a; ++i) {
			q.push(i);
		}
		
		//cout << q.back() << endl;
		int cnt = b;
		while (q.size() != 2) {
			if (cnt == b) {
				q.pop();
				cnt = 0;
			}
			else {
				int temp = q.front();
				q.push(temp);
				q.pop();
			}
			//printqueue(q);
			cnt++;
		}
		

		vector<int> pnt;
		while (!q.empty()) {
			pnt.push_back(q.front());
			q.pop();
		}
		sort(pnt.begin(), pnt.end());
		
		for (int i = 0; i < 2; ++i) {
			cout << pnt[i] << ' ';
		}
		cout << endl;
	}
	return 0;
}