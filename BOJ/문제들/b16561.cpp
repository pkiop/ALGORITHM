#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main(void) {
	int n;
	cin >> n;
	int temp;
	int ans = 0;
	for(int i=3;i<=3000;i+=3) {
		temp = n - i;
		if(temp >= 6) {
			for(int j=3;j<=3000;j+=3) {
				temp = n - i - j;
				if(temp >= 3 && temp%3 == 0) {
					//cout << i << " + " << j << " + " << temp << endl;
					ans++;
				}
			}
		}
	}
	cout << ans << endl;
}
