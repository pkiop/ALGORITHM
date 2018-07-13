#include <iostream>
#include <algorithm>
#include <queue>
#include <string>
#include <cstring>
#include <set>

using namespace std;

int num[5001];
int arr[5001];
int main(void) {
	int a, b;
	cin >> a >> b;
	int temp;
	cin >> temp;
	arr[0] = num[0] = temp;
	for (int i = 1; i < a; ++i) {
		cin >> temp;
		num[i] = temp;
		arr[i] = temp + arr[i - 1];
	}
	double ans = 0.0;
	for (int k = b; k <= a; ++k) {
		for (int i = 0; i < a; ++i) {
			for (int j = i + k - 1; j < a; ++j) {
				ans = max(ans, double(arr[j] - arr[i] + num[i]) / double(j-i+1));
			}
		}
	}
	cout.fixed;
	cout.precision(9);
	cout << ans << endl;

}



