#include <iostream>
#include <algorithm>
#include <queue>
#include <vector>
#include <map>
#include <cstring>
#include <string>

using namespace std;

int main(void) {
	string arr = "123456789";
	for (int i = 0; i < 9; ++i) {
		char temp;
		cin >> temp;
		if (temp == '0') {
			arr[i] = '9';
		}
		else {
			arr[i] = temp;
		}
	}

	map<string, int> visited;
	queue<string> q;

	visited[arr] = 0;
	q.push(arr);
	while (!q.empty()) {
		string here = q.front();
		q.pop();
		if (here == "123456789") {
			cout << visited[here] << endl;
			return 0;
		}
		int startidx;
		for (int i = 0; i < 9; ++i) {
			if (here[i] == '9') {
				startidx = i;
				break;
			}
		}

		if (startidx == 0) {
			string next = here;
			swap(next[startidx + 1], next[startidx]);
			q.push(next);
			visited[next] = visited[here] + 1;
			swap(next[startidx + 1], next[startidx]);
			swap(next[3], next[0]);
			q.push(next);
			visited[next] = visited[here] + 1;

		}
		if (startidx == 1) {
			string next = here;
			swap(next[1], next[0]);
			q.push(next);
			visited[next] = visited[here] + 1;
			swap(next[1], next[0]);
			swap(next[1], next[2]);
			q.push(next);
			visited[next] = visited[here] + 1;
			swap(next[1], next[2]);
			swap(next[1], next[4]);
			q.push(next);
			visited[next] = visited[here] + 1;
		}
		if (startidx == 2) {
			string next = here;
			swap(next[2], next[1]);
			q.push(next);
			visited[next] = visited[here] + 1;
			swap(next[2], next[1]);
			swap(next[2], next[5]);
			q.push(next);
			visited[next] = visited[here] + 1;
		}
		if (startidx == 3) {
			string next = here;
			swap(next[3], next[0]);
			q.push(next);
			visited[next] = visited[here] + 1;
			swap(next[3], next[0]);
			swap(next[3], next[4]);
			q.push(next);
			visited[next] = visited[here] + 1;
			swap(next[3], next[4]);
			swap(next[3], next[6]);
			q.push(next);
			visited[next] = visited[here] + 1;
		}
		if (startidx == 4) {
			string next = here;
			swap(next[4], next[1]);
			q.push(next);
			visited[next] = visited[here] + 1;
			swap(next[4], next[1]);
			swap(next[4], next[3]);
			q.push(next);
			visited[next] = visited[here] + 1;
			swap(next[4], next[3]);
			swap(next[4], next[5]);
			q.push(next);
			visited[next] = visited[here] + 1;
			swap(next[4], next[5]);
			swap(next[4], next[7]);
			q.push(next);
			visited[next] = visited[here] + 1;

		}
		if (startidx == 5) {
			string next = here;
			swap(next[5], next[2]);
			q.push(next);
			visited[next] = visited[here] + 1;
			swap(next[5], next[2]);
			swap(next[5], next[4]);
			q.push(next);
			visited[next] = visited[here] + 1;
			swap(next[5], next[4]);
			swap(next[5], next[8]);
			q.push(next);
			visited[next] = visited[here] + 1;
		}
		if (startidx == 6) {
			string next = here;
			swap(next[6], next[3]);
			q.push(next);
			visited[next] = visited[here] + 1;
			swap(next[6], next[3]);
			swap(next[6], next[7]);
			q.push(next);
			visited[next] = visited[here] + 1;
		}
		if (startidx == 7) {
			string next = here;
			swap(next[7], next[4]);
			q.push(next);
			visited[next] = visited[here] + 1;
			swap(next[7], next[4]);
			swap(next[7], next[6]);
			q.push(next);
			visited[next] = visited[here] + 1;
			swap(next[7], next[6]);
			swap(next[7], next[8]);
			q.push(next);
			visited[next] = visited[here] + 1;
		}
		if (startidx == 8) {
			string next = here;
			swap(next[8], next[5]);
			q.push(next);
			visited[next] = visited[here] + 1;
			swap(next[8], next[5]);
			swap(next[8], next[7]);
			q.push(next);
			visited[next] = visited[here] + 1;
		}
	}
	cout << '-1' << endl;

	return 0;
}