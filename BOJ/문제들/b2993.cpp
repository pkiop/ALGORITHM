#include <iostream>
#include <string>
#include <vector>

using namespace std;

vector<vector<int> > vt;

int max_len;
vector<int> temp;
void dfs(int remain, int cnt) {
	if(cnt == 2) {
		if(remain == 0){
			return;
		}
		temp.push_back(remain);
		vt.push_back(temp);
		temp.pop_back();
		return;
	}

	for(int i=1;i<=remain;++i) {
		temp.push_back(i);
		dfs(remain - i, cnt+1);
		temp.pop_back();
	}
} 

void print_vt() {
	for(int i=0;i<vt.size();++i) {
		for(int j=0;j<3;++j) {
			cout << vt[i][j] << ' ';
		}
		cout << endl;
	}
}

int main(void) {
	string s;
	cin >> s;
	max_len = s.size();
	dfs(max_len, 0);
	//print_vt();
	//cout << vt.size() << endl;
	string ans = "zzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzz";
	for(int i=0;i<vt.size();++i) {
		string temp_ans;
		vector<char> temp;
		//cout << vt[i][0] << ' ' << vt[i][1] << ' ' << vt[i][2] << endl;
		for(int j=0;j<vt[i][0];++j) {
			temp.push_back(s[j]);
		}
		for(int k=temp.size()-1;k>=0;k--) {
			temp_ans += temp[k];
		}
		temp.clear();
		for(int j=0;j<vt[i][1];++j) {
			temp.push_back(s[j + vt[i][0]]);
		}
		for(int k=temp.size()-1;k>=0;k--) {
			temp_ans += temp[k];
		}
		temp.clear();
		for(int j=0;j<vt[i][2];++j) {
			temp.push_back(s[j + vt[i][0] + vt[i][1]]);
		}
		for(int k=temp.size()-1;k>=0;k--) {
			temp_ans += temp[k];
		}
		temp.clear();
		//cout << vt[i].size() << endl;
		//cout << temp_ans << endl;
		if(ans > temp_ans) {
			ans = temp_ans;
		}
	}
	cout << ans << endl;}
