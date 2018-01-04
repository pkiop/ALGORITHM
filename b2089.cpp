#include <iostream>
#include <stack>

using namespace std;

stack<int> st;

int main() {
	int n;
	cin >> n;
	
	bool na;

	if (n == 0) {
		cout << 0;
		return 0;
	}
	if (n > 0) {
		na = false;
	}
	else {
		na = true;
		n *= -1;
	}

	while (n != 0) {
		st.push(n % 2);
		
		if (na) {
			if (n % 2 != 0) {
				n = n / 2 + 1;
			}
			else {
				n = n / 2;
			}
			na = false;
		}
		else {
			n = n / 2;
			na = true;
		}
	}

	while (!st.empty()) {
		cout << st.top();
		st.pop();
	}

	return 0;
}