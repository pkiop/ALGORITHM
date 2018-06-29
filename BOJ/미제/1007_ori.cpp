#include <iostream>
#include <vector>
#include <map>
#include <math.h>

using namespace std;

int n;
vector<pair<int, int>> arr;
map<pair<int, int>, bool > m;
double vectorsum;
double xx(int a, int b) {
	return double((a * a) + (b * b));
}

void go(int arridx, map<pair<int,int>,bool> &mm, double len) {
	if (arridx > n - 1) {
		return;
	}
	bool end = true;
	for (int i = 0; i < n; ++i) {
		if (mm[arr[i]] == false) {
			end = false;
		}
	}
	
	if (end) {
		double temp = len;
		//cout << x << ' ' << y << endl;
		temp = (temp >= 0 ? temp : -temp);
		if (temp < vectorsum) {
			vectorsum = temp;
		}
		return;
	}

	if (mm[arr[arridx]] == true) {
		return;
	}

	for (int i = 0; i < n; ++i) {
		if (i == arridx) {
			continue;
		}
		if (mm[arr[i]] == false) {
			mm[arr[arridx]] = true;
			mm[arr[i]] = true;
			int nx = arr[i].first - arr[arridx].first;
			int ny = arr[i].second - arr[arridx].second;
			double length;
			if (nx == 0) {
				length = ny;
			}
			else if (ny == 0) {
				length = nx;
			}
			else {
				double theta = atan2(ny, nx);
				length = ny / cos(theta);
			}
			//cout << length << endl;
			for (int j = 0; j < n; ++j) {
				go(j, mm,length+len);
			}
			mm[arr[arridx]] = false;
			mm[arr[i]] = false;
		}
	}
}


int main(void) {
	int t;
	cin >> t;
	while (t--) {
		cin >> n;
		arr.clear();
		int a, b;
		for (int i = 0; i < n; ++i) {
			cin >> a >> b;
			arr.push_back({ a,b });
		}
		vectorsum = 9999999999.0;
		for (int i = 0; i < n; ++i) {
			m.clear();
			go(i, m, 0.0);
		}
		cout.fixed;
		cout.precision(20);
		cout << vectorsum << endl;
	}
}