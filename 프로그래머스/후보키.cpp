#include <iostream>
#include <vector>
#include <string>
#include <unordered_set>
#define DEBUG
using namespace std;

int colsize;
int rowsize;
vector<string> arr[10001];
bool keyOK[10001];

bool visited[10001];
// loca는 몇번째 row인지
vector<string> hubo;
vector<vector<int> > mixedIdx;
vector<int> temp;
void makeKey(int depth, int loca, int maxDepth, int nowIdx, string nowstring) {
	if (depth == maxDepth) {
		hubo.push_back(nowstring);
		mixedIdx.push_back(temp);
		return;
	}

	for (int i = nowIdx; i < colsize; ++i) {
		if (keyOK[i] == true || visited[i] == true) continue;
		visited[i] = true;
		string newstring = nowstring + arr[i][loca];
		temp.push_back(i);
		makeKey(depth + 1, loca, maxDepth, i, newstring);
		temp.pop_back();
		visited[i] = false;
	}
}
int solution(vector<vector<string>> relation) {
	int answer = 0;
	rowsize = relation.size();
	colsize = relation[0].size();
	for (int i = 0; i < relation.size(); ++i) {
		for (int j = 0; j < relation[i].size(); ++j) {
			arr[j].push_back(relation[i][j]);
		}
	}
#ifdef DEBUG
	for (int i = 0; i < colsize; ++i) {
		for (int j = 0; j < rowsize; ++j) {
			cout << arr[i][j] << ' ';
		}
		cout << endl;
	}
#endif
	

	//컬럼 n개 
	for (int depth = 1; depth <= colsize; ++depth) {
		unordered_set<string> us[21];
		bool success[21];
		for (int i = 0; i < mixedIdx.size(); ++i) {
			mixedIdx[i].clear();
		}
		mixedIdx.clear();
		int insertcnt[21];
		for (int i = 0; i < 21; ++i) {
			success[i] = true;
			insertcnt[i] = 0;
		}
		for (int loca = 0; loca < rowsize; ++loca) {
			makeKey(0, loca, depth, 0, "");
			string Key = "";
			for (int i = 0; i < hubo.size(); ++i) {
#ifdef DEBUG
				cout << "hubo[" << i << "] : " << hubo[i] << endl;
#endif
				if (us[i].count(hubo[i]) != 0) {
					success[i] = false;
				}
				else {
					us[i].insert(hubo[i]);
					insertcnt[i]++;
				}
			}
			hubo.clear();
		}
#ifdef DEBUG
		
		cout << "success " << endl;
		for (int i = 0; i < colsize; ++i) {
			cout << success[i] << ' ';
		}
		cout << endl;
		
#endif
		for (int i = 0; i < colsize; ++i) {
			if (keyOK[i] == false && success[i] && insertcnt[i] != 0) {
				cout << "OK multi bit :: depth : " << depth << " : ";
				bool retire = false;
				for (auto x : mixedIdx[i]) 
				{
					if (keyOK[x] == true) {
						retire = true;
						break;
					}
					cout << x << ' ';
					keyOK[x] = true;
				}
				cout << endl;
				if (!retire) {
					answer++;
				}
			}
		}
#ifdef DEBUG
		cout << "depth : " << depth << endl;
		for (int i = 0; i < 8; ++i) {
			cout << keyOK[i] << ' ';
		}
		cout << endl;
		cout << "miiddle answer : " << answer << endl;
#endif
	}
	
	return answer;
}

int main(void) {
	freopen("input.txt", "r", stdin);
	int N, M;
	cin >> N >> M;
	vector<vector< string> > input;
	for (int i = 0; i < N; ++i) {
		vector<string> temp;
		string t;
		for (int j = 0; j < M; ++j) {
			cin >> t;
			temp.push_back(t);
		}
		input.push_back(temp);
	}
	cout << solution(input) << endl;
}

/*
int answer = 0;
	//컬럼 1개
	for (int i = 0; i < rowsize; ++i) {
		if (keyOK[i] == true) {
			continue;
		}
		unordered_set<string> us;
		bool fail = false;
		for (int j = 0; j < arr[i].size(); ++j) {
			if (us.count(arr[i][j]) != 0) {
				//cout << "now idx : " << i << endl;
				//cout << "arrij fail : " << arr[i][j] << endl;
				fail = true;
			}
			else {
				us.insert(arr[i][j]);
			}
		}
		if (fail) {

		}
		else {
			answer++;
			//cout << "true i : " << i << endl;
			keyOK[i] = true;
		}
	}
	//cout << "columb 1 answer : " << answer << endl;
	for (int i = 0; i < 8; ++i) {
		cout << keyOK[i] << ' ';
	}
	cout << endl;
	//컬럼 2개
	for (int i = 0; i < rowsize; ++i) {
		if (keyOK[i] == true) {
			continue;
		}
		for (int ii = i + 1; ii < rowsize; ++ii) {
			if (keyOK[ii] == true) {
				continue;
			}
			unordered_set<string> us;
			bool fail = false;
			for (int j = 0; j < arr[i].size(); ++j) {
				if (us.count(arr[i][j] + arr[ii][j]) != 0) {
					fail = true;
				}
				else {
					us.insert(arr[i][j] + arr[ii][j]);
				}
			}
			if (fail) {

			}
			else {
				answer++;
				cout << "two : " << i << ' ' << ii << endl;
				keyOK[i] = true;
				keyOK[ii] = true;
			}
		}
	}


*/
