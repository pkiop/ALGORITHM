#include <iostream>
#include <vector>
#include <algorithm>
#include <fstream>
#include <string>
#include <cstring>
#include <map>
#define GO
#define DEBUG

using namespace std;

/*

4
3 5 7 1

*/
int cntarr[101];

int main(void) {

#ifdef GO
	freopen("input.txt", "r", stdin);
#endif
	int n;
	cin >> n;
	vector<int> arr(n);
		
	for (int i = 0; i < n; ++i) {
		cin >> arr[i];
		cntarr[arr[i]]++;
	}
	int onenum = 0;
	int oddnum = 0;
	for (int i = 0; i < 101; ++i) {
		if (cntarr[i] == 1) {
			onenum++;
		}
		if (cntarr[i] > 2) {
			oddnum++;
		}
	}
	if (onenum % 2 != 0 && oddnum == 0) {
		cout << "NO";
		return 0;
	}
	cout << "YES" << endl;
	bool trig = false;
	bool once = false;
	bool seval = false; // false => A출력 
	int selectedval = -1;
	for (int i = 0; i < n; ++i) {
		if (once == false && onenum % 2 != 0 && cntarr[arr[i]] > 2) {
			if (trig) {
				cout << 'A';
				trig = false;
				seval = true;
			}
			else {
				cout << 'B';
				trig = true;
				seval = false;
			}
			selectedval = arr[i];
			once = true;
			continue;
		}
		if (cntarr[arr[i]] > 1 && arr[i] != selectedval) {
			cout << 'A';
		}
		else if (selectedval == arr[i]) {
			if (seval) {
				cout << 'B';
			}
			else {
				cout << 'A';
			}
		}
		else {
			if (trig) {
				cout << 'A';
				trig = false;
			}
			else {
				cout << 'B';
				trig = true;
			}
		}
	}








#ifdef GO
	cout << "\nerase go\n";
#endif
	return 0;
}