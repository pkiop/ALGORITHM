#include <iostream>

using namespace std;

int day[1001];
int pay[1001];

int n;

int go(int k){
	if(k >= n+1){
		return 0;
	}

	int ans = 0;
	for(int i=k+1;i<=n;++i){
		if(i+day[i] < n){
			cout << ans << endl;
			ans = max(ans,ans + pay[i] + go(i+day[i]));
		}
	}
	return ans;
}

int main(void)
{
	cin >> n;
	for(int i=1;i<=n;++i){
		cin >> day[i];
		cin >> pay[i];
	}
	int ans = 0;
	for(int i=1;i<=n;++i){
		ans = max(ans, go(i));
	}
	cout << ans << endl;
}