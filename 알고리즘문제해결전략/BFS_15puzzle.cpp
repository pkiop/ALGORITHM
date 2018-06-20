/*
	양 방향 탐색.
	완료조건이 명확한 경우 반대 방향에서도 출발해서 중간에 만나게 해서 더 
	메모리와 시간을 단축 시킬 수 있다. 
*/

#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <set>
#include <cstring>
#include <queue>
#include <algorithm>

using namespace std;

int dx[] = { 0,0,1,-1 };
int dy[] = { 1,-1,0,0 };

class State {
	vector<int> data;
	int emptylo;
public:
	State() {
		data.resize(16);
		emptylo = -1;
	}

	State(vector<int> input) {
		data.resize(16);
		data = input;
		for (int i = 0; i < 16; ++i) {
			if (input[i] == 0) {
				emptylo = i;
				break;
			}
		}
	}
	void print() const {

		for (int i = 0; i < 16; ++i) {
			
			cout << data[i] << ' ';
			if (i % 4 == 3) {
				cout << endl;
			}
		}
	}

	vector<State> getAdjacent() const {
		vector<State> ret;
		int row = emptylo / 4;
		int col = emptylo % 4;
		for (int k = 0; k < 4; ++k) {
			int nrow = row + dy[k];
			int ncol = col + dx[k];
			if (0 <= nrow && nrow < 4 && 0 <= ncol && ncol < 4) {
				vector<int> arrtemp = data;
				swap(arrtemp[emptylo], arrtemp[nrow * 4 + ncol]);
				State temp(arrtemp);
				ret.push_back(arrtemp);
			}
		}
		return ret;
	}

	bool operator < (const State& rhs) const { // <연산자 구현할 때 반드시 크다작다 다 구현 
		for (int i = 0; i < 16; ++i) {
			if (data[i] < rhs.data[i]) {
				return true;
			}
			if (data[i] > rhs.data[i]) {
				return false;
			}
		}
		return false;
	}

	bool operator == (const State& rhs) const {
		for (int i = 0; i < 16; ++i) {
			if (data[i] != rhs.data[i]) {
				return false;
			}
		}
		return true;
	}
};

int sgn(int x) { // 부호반환 함수
	if (!x) return 0; // 0이면 0 return
	return x > 0 ? 1 : -1;
}

int incr(int x) { if (x < 0) return x - 1; return x + 1; } // 역방향은 더 작게 순방향은 더 크게

typedef map<State, int> StateMap;

int bidirectional(State start, State finish) {
	StateMap c;
	queue<State> q;
	if (start == finish) return 0;
	q.push(start);
	c[start] = 1;
	q.push(finish);
	c[finish] = -1;

	while (!q.empty()) {
		State here = q.front();
		q.pop();

		vector<State> adjacent = here.getAdjacent();
		for (int i = 0; i < adjacent.size(); ++i) {
			map<State, int>::iterator it = c.find(adjacent[i]);
			if (it == c.end()) { // end는 null 과 같은 의미로 이걸 쓴 듯. 비어있다는 뜻 같은데 
				c[adjacent[i]] = incr(c[here]);
				q.push(adjacent[i]);
			}
			else if (sgn(it->second) != sgn(c[here])) // 가운데서 만난 경우. 부호가 다른 것 끼리 만나면 그렇다.
				return abs(it->second) + abs(c[here]) - 1;
		}
	}
	return -1;
}

int bfs(State start, State finish) {
	if (start == finish) {
		return 0;
	}
	StateMap c;

	queue<State> q;
	q.push(start);

	c[start] = 0;
	while (!q.empty()) {
		State here = q.front();
		q.pop();

		int cost = c[here];
		vector<State> adjacent = here.getAdjacent();
		/*cout << "c안의" << c[adjacent[0]];
		cout << "cop : " << (adjacent[0] == here);
		adjacent[0].print();
		cout << "ccc : " << c.count(adjacent[0]) << endl;
		adjacent[1].print();
		cout << "ccc : " << c.count(adjacent[1]) << endl;

		adjacent[2].print();
		cout << "ccc : " << c.count(adjacent[2]) << endl;

		cout << "Csi" << c.size();*/
		for (int i = 0; i < adjacent.size(); ++i) {
			if (c.count(adjacent[i]) == 0) {
				if (adjacent[i] == finish) return cost + 1;
				c[adjacent[i]] = cost + 1;
				q.push(adjacent[i]);
			}
		}
	}
	return -1;
}

// 점점 깊어지는 탐색

int best;

void dfs(State here, const State& finish, int steps) {
	if (steps >= best) return;

	if (here == finish) {
		best = steps; return;
	}

	vector<State> adjacent = here.getAdjacent();
	for (int i = 0; i < adjacent.size(); ++i) {
		dfs(adjacent[i], finish, steps + 1);
	}
}

int ids(State start, State finish, int growthStep) {
	for (int limit = 4; ; limit += growthStep) {
		best = limit + 1;
		dfs(start, finish, 0);
		if (best <= limit) return best;
	}
	return -1;
}

// 점점 깊어지는 탐색 끝

int main(void) {
	vector<int> arr;
	arr.push_back(0);
	arr.push_back(2);
	arr.push_back(3);
	arr.push_back(4);
	arr.push_back(5);
	arr.push_back(6);
	arr.push_back(7);
	arr.push_back(8);
	arr.push_back(9);
	arr.push_back(10);
	arr.push_back(11);
	arr.push_back(12);
	arr.push_back(13);
	arr.push_back(14);
	arr.push_back(1);
	arr.push_back(15);

	vector<int> arrf;
	arrf.push_back(1);
	arrf.push_back(2);
	arrf.push_back(3);
	arrf.push_back(4);
	arrf.push_back(5);
	arrf.push_back(6);
	arrf.push_back(7);
	arrf.push_back(8);
	arrf.push_back(9);
	arrf.push_back(10);
	arrf.push_back(11);
	arrf.push_back(12);
	arrf.push_back(13);
	arrf.push_back(14);
	arrf.push_back(15);
	arrf.push_back(0);

	State My(arr);
	State finish(arrf);

	cout << bidirectional(My, finish) << endl;

	return 0;

}