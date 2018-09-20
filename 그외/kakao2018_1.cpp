


#include <iostream>
#include <string>
#include <vector>
#include <map>

using namespace std;

vector<string> solution(vector<string> record) {
	vector<string> answer;
	vector<pair<string, bool>> arr; // false => out true -> in
	map<string, string> idtoNic;
	int len = record.size();
	for (int i = 0; i < len; ++i) {
		if (record[i][0] == 'E') {
			//E 일때 enter ... id값을 set key값으로 닉네임을 value값으로 (무조건 없으니 Enter이란 가정)
			int idx = 6; // enter' ' 빼고 인덱스시작 6
			int len2 = record[i].size();
			string f_le = "", s_le = "";
			while (record[i][idx] != ' ') { // index가 len이면 더 하면 안된다. 
				f_le += record[i][idx];
				idx++;
			}
			idx++; // 공백 띄어넘기
			while (idx != len2) {
				s_le += record[i][idx];
				idx++;
			}

			arr.push_back({ f_le, true });
			idtoNic[f_le] = s_le;
		}
		if (record[i][0] == 'L') {
			//L 일때 leave 무조건 있으니 leave할 수 있다. 
			int idx = 7;
			int len = record[i].size();
			string f_le = "";
			while (idx != len) {
				f_le += record[i][idx];
				idx++;
			}

			arr.push_back({ f_le, false });

		}
		if (record[i][0] == 'C') {
			int idx = 8; // enter' ' 빼고 인덱스시작 6
			int len2 = record[i].size();
			string f_le = "", s_le = "";
			while (record[i][idx] != ' ') { // index가 len이면 더 하면 안된다. 
				f_le += record[i][idx];
				idx++;
			}
			idx++; // 공백 띄어넘기
			while (idx != len2) {
				s_le += record[i][idx];
				idx++;
			}
			idtoNic[f_le] = s_le;
		}
	}

	for (int i = 0; i < arr.size(); ++i) {
		string temp;
		if (arr[i].second == true) {
			temp = idtoNic[arr[i].first];
			temp += "님이 들어왔습니다.";
		}
		else {
			temp = idtoNic[arr[i].first];
			temp += "님이 나갔습니다.";
		}
		answer.push_back(temp);
	}

	return answer;
}
