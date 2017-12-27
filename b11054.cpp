#include <iostream>

using namespace std;

int in[1001];
int rev[1001];
int len[1001];
int relen[1001];

int main() {
	int n;
	cin >> n;
	for (int i = 1; i <= n; ++i)
	{
		cin >> in[i];
		rev[n - i + 1] = in[i];
	}
	for (int i = 1; i <= n; ++i) {
		len[i] = 1;
		for (int j = 1; j <= n; ++j) {
			if (in[i] > in[j] && len[i] < len[j] + 1) {
				len[i] = len[j] + 1;
			}
		}
	}

	for (int i = 1; i <= n; ++i) {
		relen[i] = 1;
		for (int j = 1; j <= n; ++j) {
			if (rev[i] > rev[j] && relen[i] < relen[j] + 1) {
				relen[i] = relen[j] + 1;
			}
		}
	}
	int max = 0;
	for (int i = 1; i <= n; ++i) {
		if (max < len[i] + relen[n-i+1] - 1) {
			max = len[i] + relen[n-i+1] - 1;
		}
	}
	cout << max;

	
	return 0;

}