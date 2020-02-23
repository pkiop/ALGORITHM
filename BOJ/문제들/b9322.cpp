#include <iostream>
#include <vector>

using namespace std;

int main(void) {
	int t;
	cin >> t;
	while(t--) {
		int n;
		cin >> n;
		vector<string> first_open_key(n);
		vector<string> second_open_key(n);
		vector<string> sec(n);
		vector<int> logic(n);
		

		for(int i=0;i<n;++i) {
			cin >> first_open_key[i];
		}
		for(int i=0;i<n;++i) {
			cin >> second_open_key[i];
		}

		//cout << "for" << endl;
		for(int i=0;i<n;++i) {
			for(int j=0;j<n;++j) {
				//cout << first_open_key[i] << ' ' << second_open_key[j] << endl;
				if(first_open_key[i] == second_open_key[j]) {
					logic[i] = j;
					//cout << logic[i] << ' ';
					break;
				}
			}
		}
		for(int i=0;i<n;++i) {
			cin >> sec[i];
		}

		for(int i=0;i<n;++i) {
			cout << sec[logic[i]] << ' ';
		}
		cout << endl;

	} 
}
