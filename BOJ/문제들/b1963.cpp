#include <iostream>
#include <algorithm>
#include <vector>
#include <cstring>
#include <queue>
#include <string>

using namespace std;

bool prime[10000];
void cal_prime(void) {
	for (int i = 2; i <= 9999; ++i) {
		if (prime[i] == false) {
			for (int j = i * 2; j <= 9999;j+=i) {
				prime[j] = true;
			}
		}
	}
}

void print_prime(void) {
	for (int i = 2; i <= 9999; ++i) {
		if (prime[i] == false) {
			cout << i << endl;
		}
	}
}

int d[4] = { 1000,100,10,1 };
bool visited[10000];

struct pp {
	int node, cnt;
};

int main(void) {
	cal_prime();
	int t;
	cin >> t;
	while (t--) {
		int ans = -1;
		memset(visited, false, sizeof(visited));
		int f, e;
		cin >> f >> e;
		queue<pp> q;

		q.push({ f,0 });
		pp hh = q.front();

		visited[f] = true;
		while (!q.empty()) {
			pp here = q.front();
			q.pop();

			int Digit[4];
			int tempNum = here.node;

			if (here.node == e) {
				ans = here.cnt;
				break;
			}

			for (int i = 0; i < 4; ++i) {
				Digit[i] = tempNum / d[i];
				tempNum = tempNum % d[i];
			}
			for (int i = 0; i < 4; ++i) {
				tempNum = here.node - Digit[i] * d[i]; // 나머지 digit은 놔두고 체크할 곳만 0으로 만든다.
				for (int j = 0; j <= 9; ++j) // j 0부터하고 i == 0 천의자리만 continue
				{
					int compareNum = tempNum + d[i] * j;
					if (i == 0 && j == 0) {
						continue;
					}

					if (prime[compareNum] == false && visited[compareNum] == false) {
						visited[compareNum] = true;
						q.push({ compareNum, here.cnt + 1 });
					}
				}
			}
		}
		if (ans == -1) {
			cout << "Impossible\n";
		}
		else {
			cout << ans << '\n';
		}
	}

	return 0;
}
