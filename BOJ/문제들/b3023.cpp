#include <iostream>
#include <vector>
#include <string>

using namespace std;

vector<string> arr;
int main(void) {
	int n, m;
	cin >> n >> m;
	string s;
	int a, b;
	for(int i=0;i<n;++i) {
		cin >> s;
		arr.push_back(s);
	}

	cin >> a >> b;
	a--;b--;
	vector<vector<char> > tarr;
	for(int i=0;i<n;++i) {
		vector<char> temp;
		for(int j=0;j<m;++j) {
			temp.push_back(arr[i][j]);
		}
		for(int j=m-1;j>=0;--j) {
			temp.push_back(arr[i][j]);
		}
		tarr.push_back(temp);
	}
	for(int i=n-1;i>=0;--i) {
		vector<char> temp;
		for(int j=0;j<m;++j) {
			temp.push_back(arr[i][j]);
		}
		for(int j=m-1;j>=0;--j) {
			temp.push_back(arr[i][j]);
		}
		tarr.push_back(temp);
	}
	if(tarr[a][b] == '.') {
		tarr[a][b] = '#';
	}
	else {
		tarr[a][b] = '.';
	}

	for(int i=0;i<tarr.size();++i) {
		for(int j=0;j<tarr[i].size();++j) {
			cout << tarr[i][j];
		}
		cout << endl;
	}
	return 0;	
}
