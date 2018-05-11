#include <iostream>

using namespace std;

int in[1001];
int len[1001];

int main() {
	int n;
	cin >> n;
	for (int i = 1; i <= n; ++i) {
		cin >> in[i];
	}

	for (int i = 1; i <= n; ++i) {
		len[i] = 1;
		for (int j = 1; j <= i; ++j) {
			if (in[i] < in[j] && len[i]<len[j]+1) {
				len[i] = len[j]+1;
			}
		}
	}
	int max=0;
	for (int i = 1; i <= n; ++i) {
		if (max < len[i]) {
			max = len[i];
		}
	}
	cout << max;
	return 0;

}