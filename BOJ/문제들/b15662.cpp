#include <iostream>

using namespace std;

int wheelnum;
class wheel {
public:

  int arr[8]; // 0 -> 12시
  wheel() {

  }
  void setwheel(string s) {
    for(int i=0;i<8;++i) {
      arr[i] = s[i] - '0';
    }
    return;
  }

  void turn(int isClockwise) {
    if(isClockwise == 1) {
      int temp = arr[7];
      for(int i=7;i>0;--i) {
        arr[i] = arr[i-1];
      }
      arr[0] = temp;
    } else {
      int temp = arr[0];
      for(int i=0;i<7;++i) {
        arr[i] = arr[i+1];
      }
      arr[7] = temp;
    }
  }

  int get12() {
    return arr[0];
  }

  int get3() {
    return arr[2];
  }

  int get9() {
    return arr[6];
  }
};

wheel wh[1001];

void leftchain(int loca, int dir) {
  int i;
  for(i = loca - 1; i >= 0;i--) {
    if(wh[i+1].get9() == wh[i].get3()) {
      break;
    }
  }

  for(int j = loca - 1; j > i && j >= 0;--j) {
    dir = dir * -1;
    wh[j].turn(dir); 
  }
  return;
}

void rightchain(int loca, int dir) {
  int i;
  for(i = loca + 1; i < wheelnum ;i++) {
    if(wh[i-1].get3() == wh[i].get9()) {
      break;
    }
  }

  for(int j = loca + 1; j < i && j < wheelnum;++j) {
    dir = dir * -1;
    wh[j].turn(dir); 
  }
  return;
}


int main(void) {
  cin >> wheelnum;

  string temp;
  for(int i=0;i<wheelnum;++i) {
    cin >> temp;
    wh[i].setwheel(temp);
  }
  int t;
  cin >> t;
  int lo, turnDir;
  for (int i = 0; i < t; ++i) {
    cin >> lo >> turnDir;
    lo--;
    leftchain(lo, turnDir);
    rightchain(lo, turnDir);
    wh[lo].turn(turnDir);
  }
  int ans = 0;
  for(int i=0;i<wheelnum;++i) {
    ans += wh[i].get12();
  }
  cout << ans << endl;
  return 0;
}