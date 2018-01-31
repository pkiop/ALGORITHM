#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main(void)
{
	int t;
	cin >> t;
	vector<pair<int, int>> info;
	for (int i = 0; i < t; ++i)
	{
		int x, y;
		cin >> x >> y;
		info.push_back(make_pair(y, x));
	}

	sort(info.begin(), info.end());

	int x = info[0].second;
	int y = info[0].first;
	int cnt = 1;
	for (int i = 1; i < t; ++i)
	{
		int xx = info[i].second;
		int yy = info[i].first;
		if (xx >= y) {
			cnt++;
			x = xx;
			y = yy;
		}
	}
	cout <<cnt <<  endl;
	return 0;
}
