//절대값이 같은 음수, 양수가 있으면 음수가 더 위에 있어야 한다. 

#include <iostream>
#include <queue>
#include <functional>
#include <vector>
#include <algorithm>
#define abs(a) (a>0 ? a : -a)

using namespace std;

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	priority_queue<int, vector<int>,greater<int>> minh;
	priority_queue<int, vector<int>,less<int>> maxh;
	int n,input;
	cin >> n;
	for (int i = 0; i < n; ++i) {
		cin >> input;
		if (minh.size() == maxh.size()) {
			maxh.push(input);
		}
		else {
			minh.push(input);
		}
		if (!maxh.empty() && !minh.empty() && maxh.top() > minh.top()) {
			int a = maxh.top();
			int b = minh.top();
			maxh.pop();
			minh.pop();
			maxh.push(b);
			minh.push(a);
		}
		cout << maxh.top() << '\n';
	}
	return 0;
}