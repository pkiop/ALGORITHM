#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
using namespace std;

int main(void) {
	int n;
	cin >> n;
	int a, b = 0;
	vector<int> arr;
	for (int i = 0; i < n; ++i) {
		cin >> a;
		if (a <= b) {
			arr.push_back(b);
		}
		b = a;
	}
	arr.push_back(a);
	cout << arr.size() << endl;
	for (int i = 0; i < arr.size()-1; ++i) {
		cout << arr[i] << ' ';
	}
	cout << arr[arr.size() - 1];
	return 0;
}