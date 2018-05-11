#include <iostream>
#include <set>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int main(void) {
	set<string> s;
	int a, b;
	cin >> a >> b;
	string input;
	vector<string> output;
	for (int i = 0; i < a; ++i) {
		cin >> input;
		s.insert(input);
	}
	for (int i = 0; i < b; ++i) {
		cin >> input;
		if (s.insert(input).second == false) {
			output.push_back(input);
		}
	}
	cout << output.size() << endl;
	sort(output.begin(), output.end());
	vector<string>::iterator it;
	for (it = output.begin(); it != output.end(); ++it) {
		cout << *it << endl;
	}
	return 0;

}