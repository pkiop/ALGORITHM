#include <iostream>
#include <vector>

using namespace std;

int n, m;
int ans;
vector<int> arr;

void dfs(int value, int idx, int cnt) {
	if(value > m) {
		return;
	}
	if(cnt == 3) {
		if(value == m || ans == m) {
			ans = m;
			return;
		}
		if(value < m && ans < value) {
			ans = value;
			return;
		}
	}
	if(cnt > 3) {
		return;
	}

	for(int i=idx+1; i<arr.size(); ++i) {
		dfs(arr[i] + value, i, cnt+1);
	}
}

int main(void) {
	cin >> n >> m;
	ans = 0;
	int temp;
	for(int i=0; i<n; ++i) {
		cin >> temp;
		arr.push_back(temp);
	}

	for(int i=0; i<arr.size(); ++i) {
		dfs(arr[i], i, 1);
	}
	cout << ans << endl;
	return 0;
}

