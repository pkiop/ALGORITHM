#include <iostream>
#include <vector>
using namespace std;

int main(void) {
	int a, b;
	cin >> a >> b;
	vector<int> arr;
	int t;
	for(int i=0;i<a;++i) {
		cin >> t;
		arr.push_back(t);
	}
	int ans = 0;
	for(t = 1; t <= b; ++t) {
		for(int i=0;i<arr.size();++i) {
			if(t % arr[i] == 0) {
				ans++;
				break;
			}
		}
	}
	cout << ans << endl;
	return 0;
}
