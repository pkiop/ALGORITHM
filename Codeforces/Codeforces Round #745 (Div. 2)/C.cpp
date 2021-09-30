#include <iostream>
#include <algorithm>

using namespace std;

int table[401][401];

bool corner(int x, int y, int sx, int sy, int w, int h) {
  if(x == sx && y == sy) return true;
  if(x == sx + (w-1) && y == sy) return true;
  if(x == sx && y == sy + (h-1)) return true;
  if(x == sx + (w-1) && y == sy + (h-1)) return true;
  return false;
}

int edgeChange(int x, int y, int sx, int sy, int w, int h) {
  if(x == sx && (y != sy && y != sy + h - 1)) {
    return table[x][y] == 0 ? 1 : 0;
  };
  if(x == sx + w - 1 && (y != sy && y != sy + h - 1)) {
    return table[x][y] == 0 ? 1 : 0;
  };
  if(y == sy && (x != sx && x != sx + w - 1)) {
    return table[x][y] == 0 ? 1 : 0;
  };
  if(y == sy + h - 1 && (x != sx && x != sx + w - 1)) {
    return table[x][y] == 0 ? 1 : 0;
  };
  return 0;
}

int emptyChange(int x, int y, int sx, int sy, int w, int h) {
  if(x == sx) return 0;
  if(x == sx + w - 1) return 0;
  if(y == sy) return 0;
  if(y == sy + h - 1) return 0;
  return table[x][y] == 1 ? 1 : 0;
}

int numberOfChange(int sx, int sy, int w, int h, int maxCnt) {
  int change = 0;
  for(int y=sy; y<sy+h;++y) {
    for(int x=sx; x<sx+w; ++x) {
      if(corner(x, y, sx, sy, w, h)) continue;
      change += edgeChange(x, y, sx, sy, w, h);
      change += emptyChange(x, y, sx, sy, w, h);
      if(maxCnt <= change) {
        return maxCnt;
      }
    }
  }
  return change;
}

void printTable(int n, int m) {
  for(int i=0;i<n;++i) {
    for(int j=0;j<m;++j) {
      cout << table[j][i] << ' ';
    } 
    cout << endl;
  }
}

int main() {
  int tc;
  cin >> tc;
  for(int i=0;i<tc;++i) {
    int n, m; 
    cin >> n >> m;
    for(int y=0;y<n;++y) {
      for(int x=0;x<m;++x) {
        scanf("%1d", &table[x][y]);
      }
    }

    int ans = 99999999;
    for(int y=0;y<n-4;++y) {
      for(int x=0;x<m-3;++x) {
        for(int w=4;w<m-x + 1;++w) {
          for(int h=5;h<n-y + 1;++h) {
            ans = min(ans, numberOfChange(x, y, w, h, ans));
          }
        }
      }
    }
    cout << ans << endl;
  }
}