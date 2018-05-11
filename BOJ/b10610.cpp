#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
	string num;
	cin >> num;
	int len = num.size();
	int zero_on = 0;
	int sum = 0;
	vector<int> put;
	for (int i = 0; i < len; ++i) {
		if (num[i] - '0' == 0) {
			zero_on++ ;
		}
		else {
			int k = num[i] - '0';
			put.push_back(k);
			sum += k;
		}
	}
	if (zero_on>0 && sum % 3 == 0) {
		sort(put.begin(), put.end());
		reverse(put.begin(), put.end());
		for (int i = 0; i < put.size(); ++i) {
			cout << put[i];
		}
		for (int i = 0; i < zero_on; ++i) {
			cout << '0';
		}
		cout << endl;
	}
	else
		cout << -1 << endl;
	return 0;
}