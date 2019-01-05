#include <iostream>
#include <vector>
#include <queue>
#include <stack>
#include <algorithm>
#include <fstream>
#include <string>
#include <cstring>
#include <map>

#define pii pair<int, int>
#define pli pair<long, int>
#define mii map<int, int>
#define msi map<string, int>

typedef unsigned long long ull;
typedef long long ll;

using namespace std;



#define GO
#define DEBUG

vector<int> arr[501];
bool visited[501];

/*

5 21
-3 2 -4 -1 -5

*/

void go(int x,int cnt) {
    if (cnt == 3) {
        return;
    }
    visited[x] = true;

    int len = arr[x].size();
    for (int i = 0; i < len; ++i) {
        int next = arr[x][i];
        go(next, cnt + 1);
    }
}


int main(void) {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#ifdef GO
    freopen("input.txt", "r", stdin);
#endif

    int t, k=1;
    cin >> t;

    while (t--) {
        for (int i = 0; i < 501; ++i) {
            arr[i].clear();
        }
        memset(visited, false, sizeof(visited));

        int n, m;
        cin >> n >> m;
        for (int i = 0; i < m; ++i) {
            int a, b;
            cin >> a >> b;
            arr[a].push_back(b);
            arr[b].push_back(a);
        }
        go(1, 0);
        int ret = 0;
        for (int i = 2; i < 501; ++i) {
            if (visited[i] == true) {
                ret++;
            }
        }
        cout << '#' << k++ << ' ' << ret << '\n';
    }

#ifdef GO
    cout << "\nerase go\n";
#endif

    return 0;
}