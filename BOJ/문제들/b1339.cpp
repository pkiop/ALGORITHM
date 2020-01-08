#include <iostream>
#include <set>
#include <map>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;


vector<string> s;
set<char> possible;

vector<int> temp;
int combi_visited[10];
int real_ans = 0;

int matching[9999];

void make_matching();
int calculating();
void processing();
void make_combi();


int main(void) {
	int n;
	cin >> n;
	string ts;
	for(int i=0;i<n;++i) {
		cin >> ts;
		s.push_back(ts);
		for(int j=0;j<ts.size();++j) {
			possible.insert(ts[j]);
		}
	}

	make_combi();
	cout << real_ans << endl;

	return 0;
}

void make_matching() {
	int in_idx = 0;
	for(auto x : possible) {
		matching[int(x)] = temp[in_idx++];
	}
}

int calculating() {
	int ans = 0;
	for(auto x : s) {
		int ten = 1;
		for(int i = x.size()-1;i>=0;--i) {
			ans += ten * matching[int(x[i])];
			ten *= 10;
		}
	}
	return ans;
}

void processing() {
	//make_matching(matching);
	int in_idx = 0;
	for(auto x : possible) {
		matching[int(x)] = temp[in_idx++];
	}
	real_ans = max(calculating(), real_ans);
}

void make_combi() {
	int rep = possible.size();
	for(int i=9;i>=0 && rep != 0;--i){
		temp.push_back(i);
		rep--;
	}
	sort(temp.begin(), temp.end());
	do {
		processing();
	} while(next_permutation(temp.begin(), temp.end()));
}