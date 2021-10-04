#include <algorithm>
#include <iostream>

using namespace std;

int table[404][404];
int h_edgePrefix[404][404];
int v_edgePrefix[404][404];
int emptyPrefix[404][404];
int n, m;

void initTable() {
  for (int i = 0; i < 404; ++i) {
    for (int j = 0; j < 404; ++j) {
      h_edgePrefix[i][j] = v_edgePrefix[i][j] = emptyPrefix[i][j] =
          table[i][j] = 0;
    }
  }
}

void printTable(int table[][404]) {
  for (int i = 1; i <= n; ++i) {
    for (int j = 1; j <= m; ++j) {
      cout << table[j][i] << ' ';
    }
    cout << endl;
  }
}

void solve() {
  initTable();
  cin >> n >> m;
  for (int y = 1; y <= n; ++y) {
    for (int x = 1; x <= m; ++x) {
      scanf("%1d", &table[x][y]);
      if (table[x][y] == 0) {
        h_edgePrefix[x][y] = h_edgePrefix[x - 1][y] + 1;
        v_edgePrefix[x][y] = v_edgePrefix[x][y - 1] + 1;
        emptyPrefix[x][y] = emptyPrefix[x - 1][y] + emptyPrefix[x][y - 1];
      } else {
        h_edgePrefix[x][y] = h_edgePrefix[x - 1][y];
        v_edgePrefix[x][y] = v_edgePrefix[x][y - 1];
        emptyPrefix[x][y] = emptyPrefix[x - 1][y] + emptyPrefix[x][y - 1] + 1;
      }
    }
  }
  cout << "h" << endl;
  printTable(h_edgePrefix);
  cout << "v" << endl;
  printTable(v_edgePrefix);
  cout << "e" << endl;
  printTable(emptyPrefix);
}

int main() {
  int tc;
  cin >> tc;
  while (tc--) {
    solve();
  }
}
