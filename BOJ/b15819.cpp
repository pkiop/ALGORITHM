#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <string>

using namespace std;

vector<int> adj[1001];
int visited[1001];
int charge[] = { 500,100,50,10,5,1 };
int main(void) {
	int a, b;
	cin >> a >> b;
	vector<string> arr;
	for (int i = 0; i < a; ++i) {
		string s;
		cin >> s;
		arr.push_back(s);
	}
	sort(arr.begin(), arr.end());
	cout << arr[b - 1];
	return 0;
}