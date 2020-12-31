#include <iostream>

using namespace std;

struct can {
  bool onRobot;
  int left;
};

int N, K;
can A[1001];

void rotateA() {
  can temp = A[N * 2 - 1];
  for(int i=N * 2-1;i>=0;--i) {
    A[i] = A[i-1];
  } 
  A[0] = temp;
  if(A[N-1].onRobot) {
    A[N-1].onRobot = false;
  }
}

void move() {
  for(int i=N - 2;i>=0;--i) {
    if(A[i].onRobot) {
      int nextIdx = i + 1;
      if(!A[nextIdx].onRobot && A[nextIdx].left != 0) {
        if(nextIdx == N-1) {
          A[i].onRobot = false;
          A[nextIdx].left--;
          continue;
        }
        A[i].onRobot = false;
        A[nextIdx].onRobot = true;
        A[nextIdx].left--;
      }
    }
  }
}

void pushRobot() {
  if(!A[0].onRobot && A[0].left != 0) {
    A[0].onRobot = true;
    A[0].left--;
  }
}

int cntEmptyCan() {
  int ret = 0;
  for(int i=0;i<N * 2;++i) {
    if(A[i].left == 0) {
      ret++;
    } 
  }
  return ret;
}

void printLeft() {
  cout << "PL" << endl;
  for(int i=0;i<N * 2;++i) {
    cout << A[i].left << ' ';
  }
  cout << endl;
  for(int i=0;i<N * 2;++i) {
    cout << A[i].onRobot<< ' ';
  }
  cout << endl;
}

int main(void) {
  cin >> N >> K;
  for(int i=0;i<N * 2;++i) {
    cin >> A[i].left;
    A[i].onRobot = false;
  }

  int ans = 0;
  while(true) {
    rotateA();
    move();
    pushRobot();
    if(cntEmptyCan() >= K) {
      cout << ans;
      return 0;
    } 
    ans++;
  }
  return 0;
}