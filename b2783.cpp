#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<pair<float, pair<int, int> > > arr;

void dfs(float money, int gram) {
	if(gram == 1000) {
		cout << money << endl;
		return;
	}
	if(gram > 1000) {
		return;
	}

	for(int i=0;i<arr.size(); ++i) {
		int l_gram = arr[i].second.first;
		int l_price = arr[i].second.second;
		
	}
}
int main(void) {
	int a,b;
	cin >> a >> b;
	float aa, bb;
	aa = a;
	bb = b;
	arr.push_back(make_pair(aa / bb, make_pair(a ,b )));
	int c;
	cin >> c;
	for(int i=0;i<c;++i) {
		cin >> a >> b;
		aa = a;
		bb = b;
		arr.push_back(make_pair(aa / bb, make_pair(a ,b )));
	}
	sort(arr.begin(), arr.end());
	int t = 1000;
//	dfs();
	cout << 1000 * arr[0].first;
	return 0;
}

