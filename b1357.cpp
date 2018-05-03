#include <iostream>
#include <string>
#include <cstring>

using namespace std;

int rev(string s) {
	
	string ret = s;
	int len = s.size();
	for (int i = 0; i < len; ++i) {
		ret[len-(i+1)] = s[i];
	}

	return stod(ret);
}

int main(void)
{
	string a, b;
	cin >> a >> b;
	cout << rev(to_string(rev(a) + rev(b)));
	return 0;
}