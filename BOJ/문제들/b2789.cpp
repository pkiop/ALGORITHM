#include <iostream>
#include <string>

using namespace std;

string s = "CAMBRIDGE";
int main(void) {
	string ss;
	cin >> ss;

	bool check = false;
	for(auto xx : ss) {
		check = false;
		for(auto x : s) {
			if(xx == x) {
				check = true;
				break;
			}
		}
		if(!check) {
			cout << xx;
		}
	}
	return 0;
}
