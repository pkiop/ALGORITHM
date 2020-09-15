#include <iostream>
#include <set>
#include <vector>

using namespace std;

char table[5][5];
set<string> s;

void input() {
  for(int i=0;i<5;++i) {
    for(int j=0;j<5;++j) {
      cin >> table[i][j];
    }
  }
}

bool rangeCheck(int nx, int ny) {
  return 0 <= nx && nx < 5 && 0 <= ny && ny < 5;
}

vector<char> temp;
int dx[] = {0,0,1,-1};
int dy[] = {1,-1,0,0};
void dfs(int y, int x) {
  if(temp.size() == 6) {
    string make = "";
    for(int i=0;i<temp.size(); ++i) {
      make += temp[i];
    }
    s.insert(make);
    return;
  }

  for(int k=0;k<4;++k) {
    int nx = x + dx[k];
    int ny = y + dy[k];
    if(rangeCheck(nx, ny)) {
      temp.push_back(table[ny][nx]);
      dfs(ny, nx);
      temp.pop_back();
    }
  }
}

void processing() {
  for(int i=0;i<5;++i) {
    for(int j=0;j<5;++j) {
      temp.push_back(table[i][j]);
      dfs(i, j);
      temp.pop_back();
    }
  }

  cout << s.size();
}

int main() {
  input();
  processing();
}