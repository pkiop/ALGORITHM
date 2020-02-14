#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> arr;
int main(void) {
	int n;
	for(int i=0;i<3;++i) {
		cin >> n;
		arr.push_back(n);
	}
	sort(arr.begin(), arr.end());
	int hop;
	hop = min(arr[1] - arr[0], arr[2] - arr[1]);
	if(arr[0] + hop != arr[1]) {
		cout << arr[0] + hop;
		return 0;
	}
	if(arr[1] + hop != arr[2]) {
		cout << arr[1] + hop;
		return 0;
	}
	cout << arr[2] + hop << endl;
	return 0;

}
