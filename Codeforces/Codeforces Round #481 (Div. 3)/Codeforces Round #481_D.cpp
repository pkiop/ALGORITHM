#include <iostream>
#include <vector>
#include <algorithm>
#include <fstream>
#include <string>
#include <cstring>
#define GO

using namespace std;

/*

4
24 21 14 10

*/
int arr[100001];
bool change[100001];
int main(void) {

#ifdef GO
	freopen("input.txt", "r", stdin);
#endif

	int n;
	cin >> n;
	for (int i = 0; i < n; ++i) {
		cin >> arr[i];
	}

	int diff = arr[1] - arr[0];
	vector<int> posdiff;
	for (int i = -2; i <= 2; ++i) {
		posdiff.push_back(diff + i);
	}

	//순서를 0,-1,1순서로
	int seq[] = { 0,-1,1 };

	int i;
	int minans = 999999;
	for (int y : posdiff) {
		for(int j : seq){
			bool breaksig = false;
			memset(change, false, sizeof(change));
			int startnum = arr[0] + j;
			if (j != 0) {
				change[0] = true;
			}
			i = 1;
			while (i < n) {
				breaksig = false;
				for(int k : seq){
					if (arr[i] + k - startnum == y) {
						if (k != 0) {
							change[i] = true;
						}
						startnum = arr[i] + k;
						breaksig = true;
						break;
					}
				}
				if (!breaksig) {
					break;
				}
				i++;
			}
			if (i == n) {
				int cnt = 0;
				for (int h = 0; h < n;++h) {
					if (change[h] == true) {
						cnt++;
					}
				}
				minans = min(minans, cnt);
			}
		}
	}
	if (minans == 999999) {
		cout << -1 << endl;
		return 0;
	}

	
	cout << minans << endl;
	return 0;

	
		

}