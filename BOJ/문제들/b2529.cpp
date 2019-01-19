#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> arr;
vector<char> pp;


int main(void) {
	int n;
	cin >> n;
	char temp;
	for (int i = 0; i < n; ++i) {
		cin >> temp;
		pp.push_back(temp);
	}
	vector<vector<int>> ans;
	for (int start = 0; start + n <= 9; ++start) {
		arr.clear();
		for (int i = start; i <= start+n; ++i) {
			arr.push_back(i);
		}
		do {
			bool pass = true;
			for (int i = 0; i < n; ++i) {
				if (pp[i] == '<') {
					if (arr[i] > arr[i + 1]) {
						pass = false;
					}
				}
				else {
					if (arr[i] < arr[i + 1]) {
						pass = false;
					}
				}

			}
			if (pass) {
				ans.push_back(arr);
			}
		} while (next_permutation(arr.begin(), arr.end()));
	}
	int last = ans.size()-1;
	for (int j = 0; j < ans[last].size(); ++j) {
		cout << ans[last][j];
	}
	cout << '\n';
	for (int j = 0; j < ans[0].size(); ++j) {
		cout << ans[0][j];
	}
	cout << '\n';
	
	
	return 0;
}