#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
int a[1000001];
int main() {
	int n;
	cin >> n;
	int max = 0;
	while (n--) {
		int k;
		cin >> k;
		a[k]++;
		if (a[max] < a[k])
			max = k;
	}
	cout << max;
	
	return 0;
}