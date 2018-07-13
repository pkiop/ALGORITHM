#include <iostream>
#include <algorithm>
#include <queue>
#include <string>
#include <cstring>
#include <set>

using namespace std;

int main(void) {
	int n;
	cin >> n;
	vector<int> arr;
	for (int i = 0; i < n; ++i) {
		int t;
		cin >> t;
		arr.push_back(t);
	}
	sort(arr.begin(), arr.end());
	int maxtemp = 1;
	int temp = 1;

	for (int i = 1; i < n; ++i) {
		if (arr[i] == arr[i - 1]) {
			temp++;
		}
		else {
			if (maxtemp < temp) {
				maxtemp = temp;
			}
			temp = 1;
		}
	}
	if (maxtemp < temp) {
		maxtemp = temp;
	}

	cout << maxtemp << endl;
}



