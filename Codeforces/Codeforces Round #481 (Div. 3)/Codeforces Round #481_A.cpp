#include <iostream>
#include <vector>
#include <algorithm>
#include <fstream>
#define GO

using namespace std;

int arr[51];
bool ch[1001];
int main(void) {

#ifdef GO
	freopen("input.txt", "r", stdin);
#endif

	int n;
	cin >> n;

	for (int i = 0; i < n; ++i) {
		cin >> arr[i];
	}

	vector<int> ans;
	for (int i = n - 1; i >= 0; --i) {
		if (ch[arr[i]] == false) {
			ch[arr[i]] = true;
			ans.push_back(arr[i]);
		}
	}
	cout << ans.size() << endl;
	reverse(ans.begin(), ans.end());
	for (auto y : ans) {
		cout << y << ' ';
	}
	return 0;
	

}