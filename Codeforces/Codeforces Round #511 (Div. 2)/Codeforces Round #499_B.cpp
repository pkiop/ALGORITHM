#include <iostream>
#include <vector>
#include <algorithm>
#include <fstream>
#include <string>
#include <cstring>

#define GO
#define DEBUG1

using namespace std;

/*

4 10
1 5 2 1 1 1 2 5 7 2

*/

int arr[111];
int cntarr[111];

int main(void) {

#ifdef GO
	freopen("input.txt", "r", stdin);
#endif
	
	int n, k;
	cin >> n >> k;
	int temp;
	int maxtemp = 0;
	for (int i = 0; i < k; ++i) {
		cin >> temp;
		cntarr[temp]++;
		maxtemp = max(maxtemp, temp);
	}

	sort(cntarr, cntarr + maxtemp + 1);
#ifdef DEBUG
	for (int i = 0; i <= maxtemp; ++i) {
		cout << cntarr[i] << ' ';	
	}
#endif
	//보기좋게
	int maxcnt = 0;
	vector<int> rarr;
	for (int i = 0; i <= maxtemp; ++i) {
		if (cntarr[i] == 0) {
			continue;
		}
		maxcnt = max(maxcnt, cntarr[i]);
		rarr.push_back(cntarr[i]);
	}
#ifdef DEBUG
	cout << endl;
	for (auto y : rarr) {
		cout << y << ' ';
	}
#endif 
	
	int left = 1;
	int right = max(maxtemp, maxcnt);
	int maxday = 0;
	while (left <= right) {
		int mid = (left + right) / 2;
		//cout << mid << endl;
		int sum = 0;
		for (auto y : rarr) {
			sum += y / mid;
		}
		if (sum >= n) {
			maxday = mid;
			left = mid + 1;
		}
		else {
			right = mid -1;
		}
	}
	cout << maxday << endl;

	return 0;
}