#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>

using namespace std;

/*
  인원수 달라도 됨
  1. 뽑는 경우의 수 생성
  2. 팀 만들어서 차이 보기
  - 반복
*/
int table[21][21];
int n;

void scorePreprocessing() {
  for(int i=0;i<n;++i) {
    for(int j=i+1;j<n;++j) {
      table[i][j] += table[j][i];
    }
  }
}

void input() {
  cin >> n;
  for(int i=0;i<n;++i) {
    for(int j=0;j<n;++j) {
      cin >> table[i][j];
    } 
  }
  scorePreprocessing();
}

vector<vector<int> > cases;
vector<int> oneCase;

bool leftTeamIdx[21];
void leftTeamIdxClear() {
  memset(leftTeamIdx, false, sizeof(leftTeamIdx));
}

int calTeamScore() {
  int leftScore = 0;
  int rightScore = 0;
  for(int i=0;i<n;++i) {
    for(int j=i+1;j<n;++j) {
      if(leftTeamIdx[i] && leftTeamIdx[j]) {
        leftScore += table[i][j];  
      }
      if(!leftTeamIdx[i] && !leftTeamIdx[j]) {
        rightScore += table[i][j];  
      }
    }
  }

  return abs(leftScore - rightScore);
}

int ans = 999999;
void checkTeamScore() {
  leftTeamIdxClear();
  for(int j=0;j<oneCase.size();++j) {
    leftTeamIdx[oneCase[j]] = true;
  }
  ans = min(ans, calTeamScore());
}

bool visited[21];
void dfs(int depth, int nowidx, int maxDepth) {
  if(depth == maxDepth) {
    checkTeamScore();
    return;
  }

  for(int i=nowidx;i<n;++i) {
    if(visited[i] == false) {
      visited[i] = true;
      oneCase.push_back(i);
      dfs(depth+1, i+1, maxDepth);
      oneCase.pop_back();
      visited[i] = false;
    }
  }
}

void makePossibleCase() {
  for(int depth=1;depth<=n/2;++depth) {
    dfs(0, 0, depth);
  }
}

void processing() {
  input();
  makePossibleCase();
  cout << ans << endl;
}

int main() {
  processing();
}