#include <iostream>
#include <string>
#include <vector>

using namespace std;


vector< vector< string > > table;
int main(void) {
	int n;
	cin >> n;
	string temp;
	vector<string> ts;
	while(n--) {
		for(int i=0;i<5;++i) {
			cin >> temp;
			ts.push_back(temp);
		}
		table.push_back(ts);
		ts.clear();
	}
	int diff = 999999;
	int fst;
	int snd;
	for(int i=0;i<table.size(); ++i) {
		for(int j=i+1; j<table.size(); ++j) {
			int t_diff = 0;
			for(int y=0;y<5;++y) {
				for(int x=0;x<7;++x) {
					if(table[i][y][x] != table[j][y][x]) {
						t_diff++;
					}
				}
			}
			if(t_diff < diff) {
				fst = i;
				snd = j;
				diff = t_diff;
			}
		}
	}
	cout << fst+1 << ' ' << snd+1 << endl;
	return 0;
}
