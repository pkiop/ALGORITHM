#include <cstring>
#include <iostream>
#include <queue>
#include <string>

using namespace std;

int R, C;
char input[1501][1501];

bool isCleared[1501][1501];
bool visited[1501][1501][1501][1501];
int dx[] = {0, 0, 1, -1};
int dy[] = {1, -1, 0, 0};
int sx, sy, ex, ey;

bool checkRange(int x, int y) { return 0 <= x && x < R && 0 <= y && y < C; }

void clearIce() {
  memset(isCleared, 0, sizeof(isCleared));
  for (int i = 0; i < R; ++i) {
    for (int j = 0; j < C; ++j) {
      if (input[i][j] == '.') {
        for (int k = 0; k < 4; ++k) {
          int nx = i + dx[k];
          int ny = j + dy[k];
          if (checkRange(nx, ny) && !isCleared[i][j]) {
            if (input[nx][ny] == 'X') {
              input[nx][ny] = '.';
              isCleared[nx][ny] = true;
            }
          }
        }
      }
    }
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
}

struct mydata {
  int sx;
  int sy;
  int ex;
  int ey;
  int depth;
};

int bfs() {
  queue<mydata> q;
  mydata myx = {sx, sy, ex, ey, 0};
  visited[sx][sy][ex][ey] = true;
  q.push(myx);
  int beforeDepth = 0;
  while (!q.empty()) {
    int nowSX = q.front().sx;
    int nowSY = q.front().sy;
    int nowEX = q.front().ex;
    int nowEY = q.front().ey;
    int depth = q.front().depth;
    cout << nowSX << ',' << nowSY << ' ' << nowEX << ',' << nowEY
         << "depth : " << depth << endl;

    q.pop();
    if (beforeDepth != depth) {
      clearIce();
      beforeDepth = depth;
    }
    printInput(nowSX, nowSY, nowEX, nowEY);

    for (int k = 0; k < 4; ++k) {
      int newSX = nowSX + dx[k];
      int newSY = nowSY + dy[k];
      if (!checkRange(newSX, newSY)) continue;
      // if (newSX == ex && newSY == ey) return depth;
      for (int kk = 0; kk < 4; ++kk) {
        int newEX = nowEX + dx[kk];
        int newEY = nowEY + dy[kk];
        if (!checkRange(newEX, newEY)) continue;
        if (visited[newSX][newSY][newEX][newEY]) continue;
        if (newSX == newEX && newSY == newEY) return depth;
        if (newSX == ex && newSY == ey) return depth;
        visited[newSX][newSY][newEX][newEY] = true;
        mydata myt = {newSX, newSY, newEX, newEY, depth + 1};
        q.push(myt);
      }
    }
  }
  return -1;
}

int main() {
  cin >> R >> C;
  bool isFirst = true;
  for (int i = 0; i < R; ++i) {
    string s;
    cin >> s;
    cout << s << endl;
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
  cout << bfs() << endl;
  return 0;
}