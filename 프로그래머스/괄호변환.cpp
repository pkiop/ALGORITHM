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
            if(complete) {
			    st.push(1);
            }
		}
		else {
			rightCnt++;
			if (complete == true) {
				if (st.empty()) {
					complete = false;
				}
				else {
					st.pop();
				}
			}
		}
	}
    if(!st.empty()) {
        complete = false;
    }
	if (leftCnt == rightCnt) {
		balance = true;
	}

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
	//if (isRight(p) == 2) {
	//	return p;
	//}
	for (i = 2; i <= p.size(); i += 2) {
		string u = p.substr(0, i);
		string v = p.substr(i, p.size());

		if (isRight(u) == 2) {
			return u + vSequence(v);
		}
        if (isRight(u) == 1) {
            return uSequence(u, v);
        }
	}
    cout << "do???" << endl;
	return uSequence(p, "");
}


string solution(string p) {

	// 1단계
    

	//if (isRight(p) == 2) {
	//	return p;
	//}
	// 2단계
	for (int i = 2; i <= p.size(); i+=2) {
		string u = p.substr(0, i);
		string v = p.substr(i, p.size());
		
		if (isRight(u) > 0) {
            //cout << "i : " << i << "success " << endl;
			return uSequence(u, v);
		}
	}
    
}
