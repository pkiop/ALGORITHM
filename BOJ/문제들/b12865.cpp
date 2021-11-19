#include <iostream>

using namespace std;

int N, K;
int input[101][2];
int DP[101][100001];

int main() {
  cin >> N >> K;
  for (int i = 1; i <= N; i++) {
    cin >> input[i][0] >> input[i][1];
  }

  for (int i = 1; i <= N; i++) {
    int w = input[i][0];
    int v = input[i][1];
    for (int j = 0; j <= K; j++) {
      if (j < input[i][0])
        DP[i][j] = DP[i - 1][j];
      else
        DP[i][j] = max(DP[i - 1][j], DP[i - 1][j - w] + v);
    }
  }

  cout << DP[N][K];
}