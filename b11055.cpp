#include <iostream>

using namespace std;

int input[1001];
int s[1001];


int main() {
	int n;
	cin >> n;
	for (int i = 1; i <= n; ++i) {
		cin >> input[i];
	}
	for (int i = 1; i <= n; ++i) {
		s[i] = input[i];
		for (int j = 1; j <= i; ++j) {
			if (input[i] > input[j] && s[i] < s[j] + input[i]) {
				s[i] = s[j] + input[i];
			}
		}
	}
	int f_max = 0;
	for (int i = 1; i <= n; ++i) {
		if (f_max < s[i]) {
			f_max = s[i];
		}
	}
	cout << f_max;
	
	return 0;
}