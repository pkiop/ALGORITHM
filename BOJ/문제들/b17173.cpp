#include <iostream>
#include <vector>

using namespace std;

int main(void) {
	int n, m;
	vector<int> temp;
	cin >> n >> m;
	int sum = 0;
	int s;

	for(int i=0;i<m;++i) {
		cin >> s;
		temp.push_back(s);
	}


	for(int i=1;i<=n;++i) {
		for(int j=0;j<temp.size();++j) {
			if(temp[j] <= i && i % temp[j] == 0) {
				sum += i;
				break;
			}	
		}		
	}

	cout << sum << endl;

}
