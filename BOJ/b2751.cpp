#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
	vector<int> ans;
	int n;
	cin >> n;
	for(int i=0;i<n;++i){
		int k;
		cin >> k;
		ans.push_back(k);
	}
	sort(ans.begin(), ans.end());
	for (int i = 0; i < n; ++i) {
		cout << ans[i] << '\n';
	}
	return 0; 
}