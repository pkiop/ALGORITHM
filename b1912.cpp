#include <iostream>

using namespace std;

#define MAX(a,b) ((a),(b)?(a):(b))
int in[100001];
int sum[100001];



int main() {
	int n;
	cin >> n;
	for (int i = 0; i < n; ++i) {
		cin >> in[i];
	}
	sum[0] = in[0];
	for (int i = 1; i < n; ++i) {
		if (sum[i - 1] + in[i] > in[i]) {
			sum[i] = sum[i - 1] + in[i];
		}
		else
			sum[i] = in[i];
	}
	int max = 0;
	for (int i = 0; i < n; ++i) {
		if (max < sum[i]) {
			max = sum[i];
		}
	}
	cout << max;
	return 0;

}