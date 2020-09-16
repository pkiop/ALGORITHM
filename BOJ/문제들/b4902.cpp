#include <iostream>
#include <algorithm>
#include <cstring>

using namespace std;

int N;
int table[401][801];
int cSum[401][801];
int ans;
void input() {
  ans = -1001;
  memset(cSum, 0, sizeof(cSum));
  memset(table, 0, sizeof(table));
  for(int r=0;r<N;++r) {
    for(int c=0;c<2*r+1;++c) {
      cin >> table[r][c];
      ans = max(table[r][c], ans);
      if(c != 0) 
        cSum[r][c] += cSum[r][c-1] + table[r][c];
      else
        cSum[r][c] = table[r][c];
    }
  }
}

void cal(int r, int c) {
  int pSum = 0;
  for(int s=1;s<=N-r+1;++s) {
    if(c == 0) 
      pSum += cSum[r + s - 1][c + 2 * (s - 1)];
    else 
      pSum += cSum[r + s - 1][c + 2 * (s - 1)] - cSum[r + s - 1][c - 1];
    ans = max(pSum, ans);
  }
}

void reverseCal(int r, int c) {
 int pSum = 0;
  for(int s=1;s<=N;++s) {
    if(c >= 2 * s - 1 && 2 * r - c >= s * 2 - 1) {
      if(c - 2 * s + 1 >= 0) {
        pSum += cSum[r - s + 1][c] - cSum[r - s + 1][c - 2 * s + 1];
      } else {
        pSum += cSum[r - s + 1][c];
      }
    } else {
      break;
    }
    ans = max(pSum, ans);
  }
}

void process() {
  for(int r=N-1;r>=0;--r) {
    for(int c=0;c<2*r+1;c+=2) {
      cal(r,c);
      if(c != 2 * r) {
        reverseCal(r,c+1);
      }
    }
  } 
 }

void output() {
  static int cnt = 1;
  cout << cnt++ << ". " << ans << endl;
}

int main(void) {
  freopen("b4902.txt", "r", stdin);
  cin >> N;
  while(N != 0) {
    input();
    process();
    output();
    cin >> N;
  }
}