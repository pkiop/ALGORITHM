#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

string a, b;
int main(void) {
	cin >> a >> b;
	vector<char> out;
	reverse(a.begin(), a.end());
	reverse(b.begin(), b.end());

	int min_length;
	bool a_is_small = false;

	if(a.size() < b.size()) {
		a_is_small = true;	
		min_length = a.size();
	}
	else {
		a_is_small = false;	
		min_length = b.size();
	}

	bool carry = false;
	for(int i=0;i<min_length;++i) {
		int op1 = int(a[i] - '0');	
		int op2 = int(b[i] - '0');
		int op3 = op1 + op2;
		if(carry == true) {
			op3++;
		}
		if(op3 > 9) {
			carry = true;
			op3-=10;
		}
		else{
			carry = false;
		}
		out.push_back(op3 + '0');
	}
	if(a_is_small) {
		for(int i = min_length; i<b.size();++i) {
			int op3 = int(b[i] - '0');
			if(carry) {
				carry = false;
				op3++;
			}
			if(op3 > 9) {
				carry = true;
				op3 -= 10;
			}
			else {
				carry = false;
			}
			out.push_back(op3 + '0');
		}
	}
	else {
		for(int i = min_length; i<a.size();++i) {
			int op3 = int(a[i] - '0');
			if(carry) {
				carry = false;
				op3++;
			}
			if(op3 > 9) {
				carry = true;
				op3 -= 10;
			}
			else {
				carry = false;
			}
			out.push_back(op3 + '0');
		}
	}
	if(carry){
		out.push_back('1');
	}
	for(int i=out.size()-1;i>=0;i--) {
		cout << out[i];
	}


}
