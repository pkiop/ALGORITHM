#include <iostream>
#include <deque>

using namespace std;
int main(void) {
	ios_base::sync_with_stdio(NULL);
	int n, l;
	cin >> n >> l;
	cin.tie(NULL);
	int temp;
	deque<pair<int, int> > dq;
	for(int i=0;i<n;++i) {
		cin >> temp;	
		if(!dq.empty() && dq.front().second <= i - l) {
			dq.pop_front();
		}
		while(!dq.empty() && dq.back().first > temp) {
			dq.pop_back();
		}
		dq.push_back({temp, i});
		cout << dq.front().first << ' ';

	}
	return 0;
}
