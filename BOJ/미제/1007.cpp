#include <iostream>
#include <vector>
#include <map>
#include <math.h>

using namespace std;

int n;
vector<pair<int, int>> arr;
vector<bool> visited;

double vectorsum;


void go(int arridx, double len) {
	if (arridx > n - 1) {
		return;
	}
	bool end = true;
	for (int i = 0; i < n; ++i) {
		if (visited[i] == false) {
			end = false;
		}
	}
	
	if (end) {
		double temp = len;
		temp = (temp >= 0 ? temp : -temp);
		
		/*cout << arridx << endl;
		cout << temp << endl;*/
		if (temp < vectorsum) {
			vectorsum = temp;
		}
		return;
	}

	if (visited[arridx] == true) {
		return;
	}

	for (int i = 0; i < n; ++i) {
		if (i == arridx) {
			continue;
		}
		if (visited[i] == false) {
			visited[arridx] = true;
			visited[i] = true;
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
			cout << arr[arridx].first << ' ' << arr[arridx].second << endl;
			cout << arr[i].first << ' ' << arr[i].second << endl;
			cout << length << endl;
			for (int j = 0; j < n; ++j) {
				go(j, length+len);
			}
			visited[arridx] = true;
			visited[i] = true;
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
		
		visited.resize(n);
		for (int i = 0; i < n; ++i) {
			visited[i] = false;
		}
		for (int i = 0; i < n; ++i) {
			visited.clear();
			visited.resize(n);
			go(0, 0.0);
		}
		cout.fixed;
		cout.precision(20);
		cout << vectorsum << endl;
	}
}