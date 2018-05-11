#include <iostream>
#include <list>
#include <string>

using namespace std;

int main(void)
{
	list<char> left;
	list<char> right;

	string s;
	cin >> s;
	int s_len = s.size();
	for (int i = 0; i < s_len; ++i) { // 먼저 왼쪽에 넣기 
		left.push_back(s[i]);
	}

	int t;
	cin >> t;
	while (t--) {
		char input_char;
		cin >> input_char;
		if (input_char == 'P') {
			char push_char;
			cin >> push_char;
			left.push_back(push_char);
		}
		else if (input_char == 'L') { // 왼쪽마지막 문자를 오른쪽 처음 문자로 보내고 왼쪽 마지막 문자 제거
			if (!left.empty()) {
				right.push_front(left.back());
				left.pop_back();
			}
		}
		else if (input_char == 'D') { // 위와 반대
			if (!right.empty()) {
				left.push_back(right.front());
				right.pop_front();
			}
		}
		else if (input_char == 'B') { //
			if (!left.empty()) {
				left.pop_back();
			}
		}
	}
	list<char>::iterator it;
	for (it = right.begin(); it != right.end(); ++it) {
		left.push_back(*it);
	}

	for (it = left.begin(); it != left.end(); ++it) {
		cout << *it;
	}
	cout << endl;
	return 0;




}