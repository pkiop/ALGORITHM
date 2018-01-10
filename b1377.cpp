#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
	int n;
	cin >> n;
	vector<pair<int, int>> a(n);
	for(int i=0;i<n;++i){
		cin >> a[i].first;
		a[i].second = i;
	}
	sort(a.begin(), a.end());
	int ans = 0;
	for (int i = 0; i < n; ++i) {
		int temp = a[i].second - i+1;
		if (temp > 0 && temp > ans) {
			ans = temp;
		}
	}
	cout << ans;
	return 0;
}