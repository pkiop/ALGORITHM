#include <iostream>
#include <stack>
#include <queue>
#include <algorithm>
#include <string>

using namespace std;

int main(void)
{
	int t;
	cin >> t;
	while (t--) {
		string s;
		cin >> s;
		int len = s.size();
		stack<int> st; // 1 : [] 2 : {} 3 : ()
		bool ans = true;
		for (int i = 0; i < len; ++i) {
			if (s[i] == '[') {
				st.push(1);
			}
			if (s[i] == '{') {
				st.push(2);
			}
			if (s[i] == '(') {
				st.push(3);
			}
			if (st.empty()) { // 비어있는 상태에서 닫는 괄호가 나오면 error 이므로 바로 탈출 
				st.push(4);
				break;
			}
			if (s[i] == ')') {
				if (st.top() == 3) {
					st.pop();
				}
				else {
					st.push(4);
					break;
				}
			}
			if (s[i] == '}') {
				if (st.top() == 2) {
					st.pop();
				}
				else {
					st.push(4);
					break;
				}
			}
			if (s[i] == ']') {
				if (st.top() == 1) {
					st.pop();
				}
				else {
					st.push(4);
					break;
				}
			}
		}

		cout << (st.empty() ? "YES" : "NO") << endl;
	}
	return 0;
}