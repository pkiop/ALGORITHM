#include <iostream>
#include <algorithm>
#include <queue>
#include <string>
#include <cstring>

using namespace std;


int go(int cnt, int sum, int goal) {
	
	if (cnt > 10) return 0;
	if (sum > goal) {
		return 0;
	}
	if (sum == goal) {
		return 1;
	}
	int now = 0;
	now += go(cnt + 1, sum + 1, goal);
	now += go(cnt + 1, sum + 2, goal);
	now += go(cnt + 1, sum + 3, goal);
	return now;
}

int main(void) {
	int n;
	cin >> n;
	int temp;
	for (int i = 0; i < n; ++i) {
		cin >> temp;
		cout << go(0, 0, temp) << endl;
	}
	return 0;
}