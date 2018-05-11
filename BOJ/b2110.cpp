#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

bool check(int mid, vector<int>& a, int m){
	int cnt = 1;
	int last = a[0];
	for(int house : a){
		if(house - last >= mid){
			cnt += 1;
			last = house;
		}
	}
	return cnt >= m;
}

int main(void)
{
	int n, m;
	cin >> n >> m;
	vector<int> a(n);
	long long left = 1;
	long long right = -1;
	for(int i=0;i<n;++i){
		cin >> a[i];
	}

	sort(a.begin(),a.end());

	right = a[n-1] - a[0];

	long long ans = 0;
	while(left<=right){
		long long mid = (left + right) / 2;
		if(check(mid, a, m)){
			if(ans < mid){
				ans = mid;
			}
			left = mid + 1;
		} else {
			right = mid - 1;
		}
	}

	cout << ans << endl;
	return 0;
}