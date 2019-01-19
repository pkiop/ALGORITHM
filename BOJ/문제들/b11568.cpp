#include <iostream>
#include <algorithm>

using namespace std;

int p[1001];
int d[1001];
int main(void)
{
	int n;
	cin >> n;
	for (int i = 1; i <= n; ++i) {
		cin >> p[i];
	}

	for (int i = 1; i <= n; ++i) {
		d[i] = 1;
		for (int j = 1; j < i; ++j) {
			if (p[i] > p[j] && d[i] < d[j] + 1)
				d[i] = d[j] + 1;
		}
	}

	int max = -1;
	for (int i = 1; i <= n; ++i)
		if (max < d[i])
			max = d[i];
	cout << max << endl;
	return 0;
}