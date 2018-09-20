#include <string>
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

int stagego[501];
int stagepass[501];

vector<int> solution(int N, vector<int> stages) {
	int len = stages.size();
	for (int i = 0; i < len; ++i) {
		for (int j = 1; j <= N && j <= stages[i]; ++j) {
			if (j != stages[i]) {
				stagepass[j]++;
			}
			stagego[j]++;
		}
	}
	vector<pair<double, int>> fail;
	for (int i = 1; i <= N; ++i) {
		fail.push_back({ double(stagepass[i]) / double(stagego[i]), i });
	}

	vector<int> answer;
	sort(fail.begin(), fail.end());
	for (int i = 0; i < N; ++i) {
		answer.push_back(fail[i].second);
	}

	return answer;
}
