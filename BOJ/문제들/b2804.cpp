#include <iostream>
#include <string>
using namespace std;

int main(void) {
	string a, b;
	cin >> a >> b;
	int A_correct_idx;
	int B_jump;
	bool out = false;
	for(int i=0;i<a.size();++i) {
		for(int j=0;j<b.size();++j) {
			if(a[i] == b[j]) {
				A_correct_idx = i;
				B_jump = j;
				out = true;
			}
			if(out) {
				break;
			}
		}
		if(out == true){
			break;
		}
	}


	for(int j=0;j<b.size();++j) {
		for(int i=0;i<a.size();++i) {
			if(j == B_jump) {
				cout << a[i];
			}
			else {
				if(i == A_correct_idx) {
					cout << b[j];
				}
				else {
					cout << '.';
				}
			}
		}
		cout << endl;
	}
	return 0;
}
