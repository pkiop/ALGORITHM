#include <iostream>
#include <vector>

using namespace std;

char table[101][101];

int r, c;
bool isrootedCluster[101][101];
void rootedClusterClear() {
  for(int i=0;i<r;++i) {
    for(int j=0;j<c;++j) {
      isrootedCluster[i][j] = false;
    }
  }
}

vector<int> stickThrowRow;

void input() {
  cin >> r >> c;
  for(int i=0;i<r;++i) {
    for(int j=0;j<c;++j) {
      cin >> table[r-i-1][j];
    }
  }
  int n;
  cin >> n;
  int temp;
  for(int i=0;i<n;++i) {
    cin >> temp;
    stickThrowRow.push_back(temp); 
  }
}

bool blockErase(int row, int col) {
  if(table[row][col] == 'x') {
    table[row][col] = '.';
    return true;
  }
  return false;
}

void eraseBlock(int throwIdx, bool isRightToLeft) {
  if(isRightToLeft) {
    for(int i=0;i<c;++i) {
      if(blockErase(throwIdx, i)) return;
    }
  } else {
    for(int i=c-1;i>=0;--i) {
      if(blockErase(throwIdx, i)) return;
    }
  }
}


int dx[] = {0,0,1,-1};
int dy[] = {1,-1,0,0};
bool dfsRangeChk(int nx, int ny) {
  return (0 <= nx && nx < c && 0 <= ny && ny < r);
}

bool dfsVisited[101][101];
void dfsVisitedClear() {
  for(int i=0;i<r;++i) {
    for(int j=0;j<c;++j) {
      dfsVisited[i][j] = false;
    }
  }
}

bool columnCheckNeeded = false;
int columnList[101];
void clearColumnList() {
  for(int i=0;i<101;++i) {
    columnList[i] = 999999;
  }
}

void dfs(int row, int col) {
  for(int i=0;i<4;++i) {
    int nx = col + dx[i];
    int ny = row + dy[i];
    if(dfsVisited[ny][nx] == false && dfsRangeChk(nx, ny)) {
      if(table[ny][nx] == 'x'){
        if(columnCheckNeeded) {
          columnList[nx] = min(columnList[nx], ny);
        }
        dfsVisited[ny][nx] = true;
        dfs(ny, nx);
      }
    }
  }
}

void pasteRootedResult() {
  for(int i=0;i<r;++i) {
    for(int j=0;j<c;++j) {
      if(dfsVisited[i][j] == true) {
        isrootedCluster[i][j] = true;
      }
    }
  }
}

void rootedClusterCheck() {
  for(int i=0;i<c;++i) {
    if(isrootedCluster[0][i] == false && table[0][i] == 'x') {
      dfsVisitedClear();
      isrootedCluster[0][i] = true;
      dfs(0, i);
      pasteRootedResult();
    } 
  }
}

void findflyCluster(int i, int j) {
  dfsVisitedClear();
  dfsVisited[i][j] = true;
  columnList[j] = i;
  dfs(i, j);
}


int findDownLength() {
  int minLength = 9999999;
  for(int j=0;j<c;++j) {
    if(columnList[j] == 999999) continue;
    for(int i=0;i<r;++i) {
      if(table[i][j] == 'x') {
        if(i == columnList[j]) {
          minLength = min(minLength, i);
          break;
        } else {
          minLength = min(columnList[j] - i - 1, minLength);
        }
      }
    }
  }
  return minLength;
}

void downCluster() {
  int downLength = findDownLength();
  for (int j = 0; j < c; ++j) {
    for (int i = 0; i < r; ++i) {
      if(dfsVisited[i][j] == true) {
        table[i][j] = '.';
        table[i-downLength][j] = 'x';
      }
    }
  }
}

void flyClusterDown() {
  for(int i=0;i<r;++i) {
    for(int j=0;j<c;++j){
      if(isrootedCluster[i][j] == false && table[i][j] == 'x') {
        clearColumnList();
        columnCheckNeeded = true;
        findflyCluster(i, j);
        columnCheckNeeded = false;
        downCluster();
        return;
      }
    }
  }
}


void processing() {
  for(int i=0;i<stickThrowRow.size(); ++i) {
    eraseBlock(stickThrowRow[i]-1, i%2==0);
    rootedClusterCheck();
    flyClusterDown();
    rootedClusterClear();
  }
}

void printAnswer() {
  for(int i=0;i<r;++i) {
    for(int j=0;j<c;++j) {
      cout << table[r-i-1][j];
    }
    cout << '\n';
  }
}

int main(void) {
  // freopen("b2933.txt", "r", stdin);
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  input();
  processing();
  printAnswer();
}