#include <iostream>
#include <queue>

using namespace std;

int N, M;
char table[21][21];
struct qData {
  pair<int, int> coin1, coin2;
  int depth;
};

pair<int, int> c1, c2;
bool bC1= false;

bool isOutside(int x, int y) {
  if(0 > x || x >= M) {
    return true;
  }
  if(0 > y || y >= N) {
    return true;
  }
  return false;
}

int main(void) {
  cin >> N >> M;
  for(int y=0;y<N;++y) {
    for(int x=0;x<M;++x) {
      cin >> table[y][x];
      if(table[y][x] == 'o') {
        if(bC1) {
          c2 = make_pair(x, y);
        } else {
          c1 = make_pair(x, y);
          bC1 = true;
        }
      }
    }
  }

  queue<qData> q;
  qData initQData;
  initQData.coin1 = c1;
  initQData.coin2 = c2;
  initQData.depth = 0;
  q.push(initQData);
  int dx[4] = {1,-1,0,0};
  int dy[4] = {0,0,1,-1};
  while(!q.empty()) {
    pair<int, int> coin1 = q.front().coin1;
    pair<int, int> coin2 = q.front().coin2;
    int depth = q.front().depth;
    q.pop();
    for(int k=0;k<4;++k) {
      int nextC1X = coin1.first + dx[k];
      int nextC1Y = coin1.second+ dy[k];
      int nextC2X = coin2.first + dx[k];
      int nextC2Y = coin2.second+ dy[k];
      int outsideCnt = 0;
      if(isOutside(nextC1X, nextC1Y)) {
        outsideCnt++;
      }
      if(isOutside(nextC2X, nextC2Y)) {
        outsideCnt++;
      }
      if(outsideCnt == 1) {
        cout << depth+1;
        return 0;
      }
      if(outsideCnt == 0) {
        pair<int, int> nextC1 = make_pair(nextC1X, nextC1Y);
        pair<int, int> nextC2 = make_pair(nextC2X, nextC2Y);
        if(table[nextC1Y][nextC1X] == '#') {
          nextC1 = coin1;
        } 
        if(table[nextC2Y][nextC2X] == '#') {
          nextC2 = coin2;
        } 
        if(nextC1X == nextC2X && nextC1Y == nextC2Y) {
          continue;
        }
        if(depth != 9) {
          qData nextQData;
          nextQData.coin1 = nextC1;
          nextQData.coin2 = nextC2;
          nextQData.depth= depth+1;
          q.push(nextQData);
        }
      }
    }
  }
  cout << -1 << endl;
  return 0;
}