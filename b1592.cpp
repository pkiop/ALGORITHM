#include <iostream>

using namespace std;

int now[1001];
int main(void) {
	int n,m,l;
	cin >> n >> m >> l;
	for(int i=1;i<=n;++i) {
		now[i] = 0;
	}
	int idx = 1;
	now[1] = 1;
	int ans = 0;
	while(now[idx] != m) {
		if(now[idx] % 2 == 0) {
			idx = (idx + l) % n;
		}
		else if(now[idx] % 2 == 1) {
			idx = (idx - l + n) % n;
		}
		now[idx]++;
		ans++;
	}
	cout << ans << endl;
}
