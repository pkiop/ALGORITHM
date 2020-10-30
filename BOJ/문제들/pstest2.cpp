#include <iostream>
#include <sstream>
#include <vector>

using namespace std;

int* buildBlock;
int bwidth;
int building[101][101];
vector<pair<int, int> > pourList;
int ans = 0;

void printBuilding(int mx) {
  for(int height=mx;height>=0;--height) {
    for(int j=0;j<bwidth;++j) {
      cout << building[height][j] << ' ';
    }
    cout << endl;
  }
}

void build() {
  for(int i=0;i<bwidth;++i) {
    int idx = 0;
    while(building[idx][i] == 1) {
      idx++;
    }
    for(int j=0;j<buildBlock[i];++j) {
      building[idx+j][i] = 1;
    }
  }
}

bool leftCheck(int height, int j) {
  for(int i=0;i<j;++i) {
    if(building[height][i] == 1) {
      return true;
    }
  }
  return false;
}
bool rightCheck(int height, int j) {
  for(int i=bwidth-1;i>j;--i) {
    if(building[height][i] == 1) {
      return true;
    }
  }
  return false;
}

void pour() {
  for(int height=0;height<101;++height) {
    for(int j=0;j<bwidth;++j) {
      if(building[height][j] == 0) {
        if(leftCheck(height, j) && rightCheck(height, j)) {
          building[height][j] = 1;
          ans++;
        }
      }
    }
  }
}

void solution(int day, int width, int **blocks) {
  bwidth = width;
  // TODO: 이곳에 코드를 작성하세요. 추가로 필요한 함수와 전역변수를 선언해서 사용하셔도 됩니다.
  for(int i=0;i<day;++i) {
    buildBlock = blocks[i];
    build();
    // cout << "after build" << endl;
    // printBuilding(20);
    pour();
    // cout << "after pour" << endl;
    // printBuilding(20);
  }
	cout << ans << endl;
}
