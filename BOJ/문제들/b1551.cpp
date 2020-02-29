#include <iostream>
#include <vector>
#include <string>

using namespace std;

vector<int> arr;
int main(void) {
	int n, m;
	cin >> n >> m;
	int s;
	char ss;
	for(int i=0;i<n-1;i+=1) {
		cin >> s >> ss;
		arr.push_back(s);	
	}
	cin >> s;
	arr.push_back(s);

	while(m--) {
		for(int i=0;i<arr.size()-1;++i) {
			arr[i] = arr[i+1] - arr[i];	
		}
		arr.pop_back();
	}
	for(int i=0;i<arr.size()-1;++i) {
		cout << arr[i] << ',';
	}
	cout << arr[arr.size() - 1] << endl;
	return 0;

}
