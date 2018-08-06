#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
using namespace std;

// 홀수면 그대로 짝수면 1빼고
int main(void) {

	int n;
	cin >> n;
	vector<int> ans;
	int temp;
	for (int i = 0; i < n; ++i) {
		cin >> temp;
		if (temp % 2 == 0) {
			ans.push_back(temp - 1);
		}
		else {
			ans.push_back(temp);
		}
	}

	for (int i = 0; i < ans.size(); ++i) {
		cout << ans[i] << ' ';
	}
	return 0;
}