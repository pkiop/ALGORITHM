/* 
	메모리 사용하는게 선형으로 증가. 
	시간 매우 오래걸리고 메모리도 많이 사용 

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

typedef map<State, int> StateMap;

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

int main(void) {
	vector<int> arr;
	arr.push_back(1);
	arr.push_back(2);
	arr.push_back(3);
	arr.push_back(4);
	arr.push_back(5);
	arr.push_back(6);
	arr.push_back(7);
	arr.push_back(8);
	arr.push_back(0);
	arr.push_back(10);
	arr.push_back(11);
	arr.push_back(12);
	arr.push_back(13);
	arr.push_back(14);
	arr.push_back(9);
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

	cout << bfs(My, finish) << endl;

	return 0;

}