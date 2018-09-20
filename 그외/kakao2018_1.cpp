


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
			//E �϶� enter ... id���� set key������ �г����� value������ (������ ������ Enter�̶� ����)
			int idx = 6; // enter' ' ���� �ε������� 6
			int len2 = record[i].size();
			string f_le = "", s_le = "";
			while (record[i][idx] != ' ') { // index�� len�̸� �� �ϸ� �ȵȴ�. 
				f_le += record[i][idx];
				idx++;
			}
			idx++; // ���� ���ѱ�
			while (idx != len2) {
				s_le += record[i][idx];
				idx++;
			}

			arr.push_back({ f_le, true });
			idtoNic[f_le] = s_le;
		}
		if (record[i][0] == 'L') {
			//L �϶� leave ������ ������ leave�� �� �ִ�. 
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
			int idx = 8; // enter' ' ���� �ε������� 6
			int len2 = record[i].size();
			string f_le = "", s_le = "";
			while (record[i][idx] != ' ') { // index�� len�̸� �� �ϸ� �ȵȴ�. 
				f_le += record[i][idx];
				idx++;
			}
			idx++; // ���� ���ѱ�
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
			temp += "���� ���Խ��ϴ�.";
		}
		else {
			temp = idtoNic[arr[i].first];
			temp += "���� �������ϴ�.";
		}
		answer.push_back(temp);
	}

	return answer;
}
