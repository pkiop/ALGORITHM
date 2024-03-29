#include <cstring>
#include <iostream>
#include <queue>
#include <string>

using namespace std;

int R, C;
char input[1501][1501];

bool isCleared[1501][1501];
bool visited[1501][1501];
int dx[] = {0, 0, 1, -1};
int dy[] = {1, -1, 0, 0};
int sx, sy, ex, ey;

bool checkRange(int x, int y) { return 0 <= x && x < R && 0 <= y && y < C; }
queue<pair<pair<int, int>, int> > iceQueue;

void findIce() {
  memset(isCleared, 0, sizeof(isCleared));
  for (int i = 0; i < R; ++i) {
    for (int j = 0; j < C; ++j) {
      if (input[i][j] == '.') {
        for (int k = 0; k < 4; ++k) {
          int nx = i + dx[k];
          int ny = j + dy[k];
          if (checkRange(nx, ny) && !isCleared[i][j]) {
            if (input[nx][ny] == 'X') {
              iceQueue.push(make_pair(make_pair(nx, ny), 1));
              isCleared[nx][ny] = true;
            }
          }
        }
      }
    }
  }
}

void clearIce() {
  int qLength = iceQueue.size();
  while (qLength--) {
    int nowX = iceQueue.front().first.first;
    int nowY = iceQueue.front().first.second;
    int nowDepth = iceQueue.front().second;
    iceQueue.pop();
    for (int k = 0; k < 4; ++k) {
      int nx = nowX + dx[k];
      int ny = nowY + dy[k];
      if (checkRange(nx, ny) && !isCleared[nx][ny]) {
        if (input[nx][ny] == 'X') {
          iceQueue.push(make_pair(make_pair(nx, ny), nowDepth + 1));
          isCleared[nx][ny] = true;
        }
      }
    }
    input[nowX][nowY] = '.';
  }
}

void printInput(int sx = -1, int sy = -1, int ex = -1, int ey = -1) {
  for (int i = 0; i < R; ++i) {
    for (int j = 0; j < C; ++j) {
      if (i == sx && j == sy) {
        cout << 'S' << ' ';
      } else if (i == ex && j == ey) {
        cout << 'E' << ' ';
      } else {
        cout << input[i][j] << ' ';
      }
    }
    cout << endl;
  }
  cout << endl;
}

struct mydata {
  int sx;
  int sy;
  int depth;
};

bool visit = false;
queue<pair<pair<int, int>, int> > nextStart;
void dfs(int x, int y, int depth, bool isFirstTry = false) {
  if (x == ex && y == ey) {
    visit = true;
    return;
  };
  for (int k = 0; k < 4; ++k) {
    int nx = x + dx[k];
    int ny = y + dy[k];
    if (checkRange(nx, ny) && input[nx][ny] != 'X' && !visited[nx][ny]) {
      visited[nx][ny] = true;
      dfs(nx, ny, depth, isFirstTry);
    } else if (checkRange(nx, ny) && input[nx][ny] == 'X' && !visited[nx][ny]) {
      nextStart.push(make_pair(make_pair(nx, ny), depth));
      visited[nx][ny] = true;
    }
  }
}

int main() {
  cin >> R >> C;
  bool isFirst = true;
  for (int i = 0; i < R; ++i) {
    string s;
    cin >> s;
    for (int j = 0; j < C; ++j) {
      input[i][j] = s[j];
      if (input[i][j] == 'L') {
        if (isFirst) {
          sx = i, sy = j;
          isFirst = false;
        } else {
          ex = i, ey = j;
        }
        input[i][j] = '.';
      }
    }
  }
  nextStart.push(make_pair(make_pair(sx, sy), 0));
  findIce();
  for (int i = 0; i < max(R, C); ++i) {
    int nowDepth = nextStart.front().second;
    // cout << " ice length : " << iceQueue.size() << endl;
    while (nowDepth == i) {
      int nx = nextStart.front().first.first;
      int ny = nextStart.front().first.second;
      nowDepth = nextStart.front().second;
      if (input[nx][ny] == 'X') break;
      nextStart.pop();
      dfs(nx, ny, i + 1, i == 0);
      if (visit) {
        cout << i << endl;
        return 0;
      }
    }
    clearIce();
    // printInput();
  }
  return 0;
};