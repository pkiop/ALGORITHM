#include <iostream>
#include <cstring>
#include <string>
#include <algorithm>

using namespace std;

typedef long long ll;
ll tb1[100001];
ll che1[100001];
ll n;
ll maxnum = -1;

int main(void)
{
	int t;
	cin >> t;
	while(t--){
		memset(che1,-1,sizeof(che1));
		memset(tb1,0,sizeof(tb1));
		maxnum = -1;
		cin >> n;
		for(int i=0;i<n;++i){
			cin >> tb1[i];
		}
		che1[0] = tb1[0];
		maxnum = tb1[0];
		for(int i=1;i<n;++i){
			che1[i] = max(tb1[i],che1[i-1]+tb1[i]);
			maxnum = max(maxnum,che1[i]);
		}
		cout << maxnum << endl;
	}
	return 0;
}