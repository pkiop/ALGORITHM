#include <iostream>
#include <algorithm>
#include <map>

using namespace std;

int N;
int table[401][801];
int ans;
void input() {
  ans = -1001;
  for(int r=0;r<N;++r) {
    for(int c=0;c<2*(r+1)-1;++c) {
      cin >> table[r][c];
      memo[r][c][1] = table[r][c];
      ans = max(table[r][c], ans);
    }
  }
}

void debugPrintTable() {
  cout << "debug print table" << endl;
  for(int r=0;r<2*N-1;++r) {
    for(int c=0;c<2*N-1;++c) {
      cout << table[r][c] << ' ';
    }
    cout << endl;
  }
}

// void debugMemoTable() {
//   for(int k=1;k<=N;++k) {
//     cout << "\nK = " << k << endl;
//     for(int r=0;r<=N;++r) {
//       for(int c=0;c<2*(r+1)-1;++c) {
//         cout << memo[r][c][k] << ' ';
//       }
//       cout << endl;
//     }
//   }
// }

void cal(int r, int c, int k) {
  if(k == 2) {
    memo[r][c][k] = memo[r][c][1] + memo[r+1][c][k-1] + memo[r+1][c+2][k-1] + memo[r+1][c+1][1];
  } else {
    memo[r][c][k] = memo[r][c][1] + memo[r+1][c][k-1] + memo[r+1][c+2][k-1] + memo[r+1][c+1][1] - memo[r+2][c+2][k-2];
  }
  ans = max(memo[r][c][k], ans);
}

void process() {
  for(int r=N-1;r>=0;--r) {
    for(int c=0;c<2*(r+1)-1;c+=2) {
      for(int k = 2; k <= N - r; ++k) { // size
        cal(r,c,k);
      }
    }
  }
}

void output() {
  static int cnt = 1;
  cout << cnt++ << ". " << ans << endl;
}

int main(void) {
  // freopen("b4902.txt", "r", stdin);
  cin >> N;
  while(N != 0) {
    input();
    // debugPrintTable();
    process();
    // debugMemoTable();
    output();
    cin >> N;
  }
}