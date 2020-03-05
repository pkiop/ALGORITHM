#include <iostream>
#include <vector>

using namespace std;

char table[7][7];
bool visited[7][7];

int n;
vector<pair<int, int> > S;
vector<pair<int, int> > cases;
bool find_Teacher(int Sx, int Sy) {
	for(int x = Sx-1; x >= 0; x--) {
		if(table[x][Sy] == 'T')  {
			return false;
		}
		if(table[x][Sy] == 'O'){
			break;
		}
	}
	for(int x = Sx+1; x < n ; x++) {
		if(table[x][Sy] == 'T')  {
			return false;
		}
		if(table[x][Sy] == 'O'){
			break;
		}
	}
	for(int y = Sy-1; y >= 0; y--) {
		if(table[Sx][y] == 'T')  {
			return false;
		}
		if(table[Sx][y] == 'O'){
			break;
		}
	}
	for(int y = Sy+1; y < n; y++) {
		if(table[Sx][y] == 'T')  {
			return false;
		}
		if(table[Sx][y] == 'O'){
			break;
		}
	}
	return true;
}

bool ans = false;
void dfs() {
	if(cases.size() == 3) {
		for(int i=0;i<3;++i) {
			table[cases[i].first][cases[i].second] = 'O';
		}
		
		for(int j=0;j<S.size();++j) {
			if(!find_Teacher(S[j].first, S[j].second)) {
				for(int i=0;i<3;++i) {
					table[cases[i].first][cases[i].second] = 'X';
				}
				return;
			}
		}

		ans = true;
		return;
	}
	if(ans == true) {
		return;
	}
	for(int y=0;y<n;++y) {
		for(int x=0;x<n;++x) {
			if(table[x][y] == 'X' && visited[x][y] == false) {
				visited[x][y] = true;
				cases.push_back({x, y});
				dfs();
				if(ans == true) {
					return;
				}
				cases.pop_back();
				visited[x][y] = false;
			}
		}
	}
}

int main(void) {
	cin >> n;
	for(int y=0;y<n;++y) {
		for(int x=0;x<n;++x) {
			cin >> table[x][y];
			if(table[x][y] == 'S') {
				S.push_back({x, y});
			}
		}
	}
	dfs();
	if(ans == true) {
		cout << "YES";
	}
	else {
		cout << "NO";
	}
	return 0;
}
