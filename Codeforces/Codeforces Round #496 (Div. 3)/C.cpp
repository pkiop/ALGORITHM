#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
using namespace std;
int arr[120001];
bool goodnum[120001];

bool ch(int a, int b) {
	int sum = a + b;
	//10억전까지
	if (sum == (sum&-sum)) {
		return true;
	}
	return false;
}

int main(void) {
	
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);
	int n;
	cin >> n;
	for (int i = 0; i < n; ++i) {
		cin >> arr[i];
	}
	int cnt = 0;
	int sum = 0;
	for (int i = 0; i < n; ++i) {
		if (goodnum[i] == true) {
			continue;
		}
		for (int j = 0; j < n; ++j) {

			if (i == j) {
				continue;
			}
			sum = arr[i] + arr[j];
			if (sum == (sum&-sum)) {
				if (goodnum[i] == false) {
					cnt++;
					goodnum[i] = true;
				}
				if (goodnum[j] == false) {
					cnt++;
					goodnum[j] = true;
				}
			}
		}
	}
	
	cout << n - cnt;

	return 0;
}