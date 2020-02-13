#include <iostream>
#include <string>

using namespace std;

int arr[1001];
int main(void) {
	int a,b;
	cin >> a >> b;
	int k = 1;
	int cnt = 0;
	for(int i=1;i<=1000;++i) {
		arr[i] = k;
		cnt++;
		if(cnt == k) {
			cnt = 0;
			k++;
		}
	}
	int ans = 0;
	for(int i=a;i<=b;++i) {
		ans += arr[i];
	}
	cout << ans << endl;
	return 0;
}
