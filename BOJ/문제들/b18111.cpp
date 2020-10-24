#include <iostream>

using namespace std;

int n, m, b;
int table[501][501];
int solution(int h) {
  int exceedBlock = 0;
  int needBlock = 0;
  for(int y=0;y<n;++y) {
    for(int x=0;x<m;++x) {
      if(table[y][x] > h) {
        exceedBlock += (table[y][x] - h);
      } else if(table[y][x] < h) {
        needBlock += (h - table[y][x]);
      }
    }
  }
  if(exceedBlock + b < needBlock) {
    return -1;
  } else {
    return exceedBlock * 2 + needBlock;
  }
}

int main(void) {
  cin >> n >> m >> b;
  for(int i=0;i<n;++i) {
    for(int j=0;j<m;++j) {
      cin >> table[i][j];
    }
  }

  int maxHeight = 256;
  int minTime = 99999999;
  for(int h=256; h>=0;--h) {
    int res = solution(h);
    if(res == -1) continue;
    if(res < minTime) {
      maxHeight = h;
      minTime = res;
    }
  }
  cout << minTime << ' ' << maxHeight  << endl;
  return 0;
}