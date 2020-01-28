#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int N;
int M;
int table[201][201];
int visited[201];
vector<int> plan;

void bfs(int start) {
	queue<int> q;
	q.push(start);
	visited[start] = true;

	while (!q.empty()) {
		int n_node = q.front();
		q.pop();
		for (int i = 1; i <= N; ++i) {
			if (visited[i] == false && table[n_node][i] == 1) {
				visited[i] = true;
				q.push(i);
			}
		}
	}
}
void print_visited() {
	for (int i = 1; i <= N; ++i) {
		cout << visited[i] << ' ';
	}
	cout << endl;
}
int main(void) {
	cin >> N >> M;
	for (int i = 1; i <= N; ++i) {
		for (int j = 1; j <= N; ++j) {
			cin >> table[j][i];
		}
	}
	int temp;
	for (int i = 0; i < M; ++i) {
		cin >> temp;
		plan.push_back(temp);
	}
	bfs(plan[0]);
	//print_visited();
	for (int i = 0; i < M; ++i) {
		if (visited[plan[i]] == false) {
			cout << "NO" << endl;
			return 0;
		}
	}
	cout << "YES" << endl;
}
