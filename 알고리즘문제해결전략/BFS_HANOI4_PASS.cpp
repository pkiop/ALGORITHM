/*
	양 방향 탐색.
	완료조건이 명확한 경우 반대 방향에서도 출발해서 중간에 만나게 해서 더 
	메모리와 시간을 단축 시킬 수 있다. 
*/

#include <iostream>
#include <vector>
#include <string>
#include <map>
//#include <set>
#include <cstring>
#include <queue>
#include <algorithm>
#include <bitset>

using namespace std;

const int MAX_DISCS = 12;

//상태를 정수 하나로 표현할 수 있기 때문에 각 상태를 방문했는지 여부를 map 대신 배열로 표현
int c[1 << (MAX_DISCS * 2)];
int sgn(int x) {
	if (!x) return 0;
	return x > 0 ? 1 : -1;
}

int incr(int x) {
	if (x < 0)
		return x - 1;
	return x + 1;
}
int get(int state, int index) {
	return (state >> (index * 2)) & 3;
}

int set(int state, int index, int value) {
	return (state & ~(3 << (index * 2))) | (value << (index * 2));
}

int bidir(int discs, int begin, int end) {
	if (begin == end) return 0;
	queue<int> q;
	memset(c, 0, sizeof(c));
	q.push(begin);
	c[begin] = 1;
	q.push(end);
	c[end] = -1;
	while (!q.empty()) {
		int here = q.front();
		q.pop();
		int top[4] = { -1,-1,-1,-1 };
		for (int i = discs - 1; i >= 0; --i)
			top[get(here, i)] = i;
		for (int i = 0; i < 4; ++i) {
			if (top[i] != -1) {
				for (int j = 0; j < 4; ++j) {
					if (i != j && (top[j] == -1 || top[j] > top[i])) {
						int there = set(here, top[i], j);
						if (c[there] == 0) {
							c[there] = incr(c[here]);
							q.push(there);
						}
						else if (sgn(c[there]) != sgn(c[here]))
							return abs(c[there]) + abs(c[here]) - 1;
					}
				}
			}
		}
	}
	return -1;
}






int bfs(int discs, int begin, int end) {
	if (begin == end) return 0;
	queue<int> q;
	memset(c, -1, sizeof(c));
	q.push(begin);
	c[begin] = 0;
	while (!q.empty()) {
		int here = q.front();
		q.pop();
		int top[4] = { -1,-1,-1,-1 };
		for (int i = discs - 1; i >= 0; --i) {
			top[get(here, i)] = i;
		}

		for (int i = 0; i < 4; ++i) {
			if (top[i] != -1) {
				for (int j = 0; j < 4; ++j) {
					if (i != j && (top[j] == -1 || top[j] > top[i])) {
						int there = set(here, top[i], j);
						if (c[there] != -1) continue;
						c[there] = c[here] + 1;
						if (there == end) return c[there];
						q.push(there);
					}
				}
			}
		}
	}
	return -1;
}

int main(void) {
	int t;
	cin >> t;

	
	while (t--) {
		int N;
		cin >> N;
		int fend = 0;
		for (int i = N-1; i >= 0; --i) {
			fend = set(fend, i, 3);
		}
		int state = 0;
		for (int i = 0; i < 4; ++i) {
			int l;
			cin >> l;
			while (l--) {
				int n;
				cin >> n;
				n--;
				state = set(state, n, i);
			}
		}
		cout << bidir(N, state, fend) << endl;

	}
}