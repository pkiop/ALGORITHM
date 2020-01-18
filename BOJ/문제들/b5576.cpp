#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main(void) {

	vector<int> a;
	vector<int> b;
	int temp;
	for(int i=0;i<10;++i) {
		cin >> temp;
		a.push_back(temp);
	}
	for(int i=0;i<10;++i){
		cin >> temp;
		b.push_back(temp);
	}
	sort(a.begin(), a.end());
	sort(b.begin(), b.end());
	cout << a[9] + a[8] + a[7] << ' ' << b[9] + b[8] + b[7] << endl;
	return 0;
}
