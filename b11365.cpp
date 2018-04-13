#include <iostream>
#include <algorithm>
#include <vector>
#include <cstring>
#include <string>

using namespace std;

int main(void)
{

	string s;
	while (getline(cin,s) && s != "END") {
		int len = s.size();
		for (int i = len - 1; i >= 0; --i) {
			cout << s[i];
		}
		cout << '\n';
	}


	return 0;
}