#include <iostream>
#include <vector>

using namespace std;

void print_fill(vector<int>& fill) {
	int len = fill.size();
	for (int i = 0; i < len; ++i) {
		cout << fill[i] << ' ';
	}
	cout << endl;
	return;
}

void go(vector<int>& arr, vector<int>& fill,int idx) {
	int fills = fill.size();
	if (fills == 6) {
		print_fill(fill);
		return;
	}
	
	int len = arr.size();
	for (int i = idx; i < len; ++i) {
		fill.push_back(arr[i]);
		go(arr, fill,i+1);
		fill.pop_back();
	}
}



int main(void) {
	int t;
	while (cin >> t && t != 0) {
		vector<int> arr(t);
		for (int i = 0; i < t; ++i) {
			cin >> arr[i];
		}
		vector<int> fill;
		go(arr, fill,0);
		arr.clear();
		fill.clear();
		cout << endl;
	}
}