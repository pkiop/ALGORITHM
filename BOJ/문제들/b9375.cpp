#include <iostream>
#include <map>
#include <string>
#include <vector>
using namespace std;

map<string, int> mp;


int main(void) {
	int t;
	cin >> t;
	string temp;
	while(t--) {
		int n;
		cin >> n;
		for(int i=0;i<n;++i) {
			cin >> temp;
			cin >> temp;
			mp[temp]++;	
		}

		int result = 1;
		for(auto x : mp) {
			result *= (x.second + 1);
		}
		cout << result - 1 << '\n';
		

		mp.clear();
	}
}
