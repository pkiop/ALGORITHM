#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
	int n;
	cin >> n;
	long long a[1000001];
	long long max = 0,maxk = 0;
	for(int i=0;i<n;++i){
		cin >> a[i];
	}
	sort(a, a + n);
	int cnt=0,maxcnt=0;
	for (int i = 1; i < n; ++i) {
		if (a[i] == a[i - 1]) {
			cnt++;
		}
		else {
			if (maxcnt < cnt) {
				maxcnt = cnt;
				maxk = i-1;
				
			}
			cnt = 0;
		}
	}
	if (maxcnt < cnt) {
		maxk = n - 1;
	}

	cout << a[maxk];
	return 0;
}