#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>

using namespace std;

int arr[101][101];
int ans[101];
int main(void) {
	int t=10;
	for (int T = 1; T <= t; ++T) {
		int temp;
		cin >> temp;
		vector<int> start;
		memset(ans, 0, sizeof(ans));
		for (int i = 0; i < 100; ++i) {
			for (int j = 0; j < 100; ++j) {
				cin >> arr[i][j];
				if (i == 0 && arr[i][j] == 1) {
					start.push_back(j);
				}
			}
		}
		int location;
		for (auto x : start) {
			int length = 0;
			location = x;
			for (int depth = 0; depth < 100; ++depth) {
				length++;
				if (location - 1 != -1 && arr[depth][location - 1] == 1) {
					location--;
					length++;
					while (location != -1 && arr[depth+1][location] == 0) {
						location--;
						length++;
					}
				}
				else if (location + 1 != 100 && arr[depth][location + 1] == 1) {
					location++;
					length++;
					while (location != -1 && arr[depth+1][location] == 0) {
						location++;
						length++;
					}
				}
			}
			ans[x] = length;
		}
		int output = 999999;
		int outidx = 0;
		for (int i = 0; i < 100; ++i) {
			if (ans[i] != 0 && output >= ans[i]) {
				output = min(output, ans[i]);
				outidx = i;
			}
		}
		cout << '#' << T << ' ' << outidx << endl;
		start.clear();
	}
}