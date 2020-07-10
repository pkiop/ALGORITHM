#include <iostream>
#include <string>
#include <vector>
#include <stack>
using namespace std;



// 0 -> 균형잡히지도 않음
// 1 -> 균형잡힌 괄호 문자열
// 2 -> 완성
int isRight(string s) {
	bool balance = false;
	bool complete = true;
	int leftCnt = 0;
	int rightCnt = 0;
	stack<int> st;

	for (int i = 0; i < s.size(); ++i) {
		if (s[i] == '(') {
			leftCnt++;
			st.push(1);
		}
		else {
			rightCnt++;
			if (complete == true) {
				if (st.empty()) {
					//cout << "anotherfail" << endl;
					complete = false;
				}
				else {
					st.pop();
				}
			}
		}
	}
	if (leftCnt == rightCnt) {
		balance = true;
	}
	//cout << "complete : " << complete << endl;
	//cout << "balance : " << balance << endl;
	if (complete) {
		return 2;
	}
	else if (balance) {
		return 1;
	}
	return 0;
}
string vSequence(string p);

string uSequence(string u, string v) {
	string answer = "";
	int isRightRet = isRight(u);
	if (isRightRet == 2) {
		answer += u + vSequence(v);
	}
	else if (isRightRet == 1) {
		string newu = "";
		for (int i = 1; i < u.size()-1; ++i) {
			if (u[i] == '(') {
				newu += ')';
			}
			else {
				newu += '(';
			}
		}
		answer += "(" + vSequence(v) + ")" + newu;
	}

	return answer;
}

string vSequence(string p) {
	int i;
	if (p == "") {
		return "";
	}
	if (isRight(p) == 2) {
		return p;
	}
	for (i = 2; i <= p.size(); i += 2) {
		string u = p.substr(0, i);
		string v = p.substr(i, p.size());

		if (isRight(u) > 0) {
			return uSequence(u, v);
		}
	}
	return uSequence(p, "");
}


string solution(string p) {
	// 1단계
	if (p == "") {
		return p;
	}

	if (isRight(p) == 2) {
		return p;
	}
	// 2단계
	for (int i = 2; i <= p.size(); i+=2) {
		string u = p.substr(0, i);
		string v = p.substr(i, p.size());
		
		if (isRight(u) > 0) {
			return uSequence(u, v);
		}
	}
}



int main(void) {
	freopen("input.txt", "r", stdin);
	string s, s2;
	while (1) {
		cin >> s;
		if (s[0] == 'o') {
			break;
		}
		string answer = solution(s);
		cin >> s2;
		if (answer == s2) {
			cout << "Success : " << answer << endl;
		}
		else {
			cout << "fail : " << answer << " , " << s2 << endl;
		}
	}

}
