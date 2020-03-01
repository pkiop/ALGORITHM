
#include <iostream>

using namespace std;

int main(void) {
	string s;
	cin >> s;
	int a = 0;	
	int b = 0;
	for(int i=0;i<s.size()/2;++i) {
		a += s[i] - '0';	
	}
	for(int i=s.size()/2; i<s.size();++i) {
		b += s[i] - '0';
	}
	if ( a == b ) {
		cout << "LUCKY" << endl;
	}
	else {
		cout << "READY" << endl;
	}
	return 0;
}
