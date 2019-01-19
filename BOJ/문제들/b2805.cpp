#include <iostream>
#include <vector> 

using namespace std;

bool check(int mid, vector<int> a, int m){
	int cnt = 0;
	int len = a.size();
	for(int i=0; i<len; ++i){
		if(a[i]-mid > 0)
			cnt += a[i] - mid;
	}
	return cnt >= m;
}



int main(void)
{
	int n, m;
	int left = 1, right = -1;
	cin >> n >> m;
	vector<int> a(n);
	for(int i=0; i<n; ++i)	{
		cin >> a[i];
		if(a[i] > right)
			right = a[i];
	}

	int ans = 0;
	
	while(left <= right){
		int mid = (left + right) / 2;
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