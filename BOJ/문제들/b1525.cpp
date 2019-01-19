#include <iostream>
#include <algorithm>
#include <queue>
#include <vector>
#include <map>
#include <cstring>
#include <string>

using namespace std;

int dx[] = { 1,-1,0,0 };
int dy[] = { 0,0,-1,1 };

int main(void) {
	int num = 0;
	for (int i = 0; i < 9; ++i) {
		int temp;
		cin >> temp;
		if (temp == 0) {
			temp = 9;
		}
		num = temp + num * 10;
	}
	map<int, int> visited;
	queue<int> q;

	q.push(num);
	visited[num] = 0;

	while (!q.empty()) {
		int x = q.front();
		q.pop();

		string here = to_string(x);

		int startidx = here.find('9');
	
		int row = startidx / 3;
		int col = startidx % 3;

		for (int i = 0; i < 4; ++i) {
			int nrow = row + dy[i];
			int ncol = col + dx[i];
			if (0 <= nrow && nrow < 3 && 0 <= ncol && ncol < 3) {
				string temp = here;
				swap(temp[startidx], temp[3 * nrow + ncol]);
				int next = stoi(temp);

				if (visited.count(next) == 0) {
					q.push(next);
					visited[next] = visited[x] + 1;
				}
			}
		}
	}

	if (visited.count(123456789) == 0) {
		cout << -1 << endl;
	}
	else {
		cout << visited[123456789] << '\n';
	}

	return 0;
}