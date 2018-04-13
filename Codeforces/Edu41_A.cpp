#include <iostream>
#include <algorithm>
#include <cstring>
#include <string>
#include <limits.h>
#include <queue>
#include <stack>

using namespace std;

int tb1[100001];
int che[100001];
bool doo[100001];
int n, m;

int main(void)
{
	cin >> n >> m;
	
	for (int i = 0; i < n; ++i) {
		cin >> tb1[i];
	}
	int ans = 0;
	for (int i = 0; i < n; ++i) {
		int k;
		cin >> k;
		che[i] = k;
		if (k == 1) {
			ans += tb1[i];
		}
	}
	int tempans = ans;
	
	for (int k = 0; k < m; ++k) {
		if (che[k] == 0) {
			tempans += tb1[k];
		}
	}
	int tempansmax = tempans;
	for (int i = 1; i < n-m+1; ++i) {
		if (che[i - 1] == 0) {
			tempans -= tb1[i - 1];
		}
		if (che[i + m-1] == 0) {
			tempans += tb1[i + m-1];
		}
		tempansmax = max(tempansmax, tempans);
	}
	cout << tempansmax << endl;
	return 0;
}