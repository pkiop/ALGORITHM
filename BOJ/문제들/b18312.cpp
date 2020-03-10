#include <iostream>

using namespace std;

int arr[3];
int main(void) {
	int n, k;
	cin >> n >> k;
	int cnt= 0;
	while(!(arr[0] == n+1 && arr[1] == 0 && arr[2] == 0)) {
		if(arr[0] / 10 == k || arr[0] % 10 == k || arr[1] / 10 == k || arr[1] % 10 == k || arr[2] / 10
				== k || arr[2] % 10 == k) {
			cnt++;
		}
		arr[2]++;
		if(arr[2] == 60) {
			arr[2] = 0;
			arr[1]++;
		}
		if(arr[1] == 60) {
			arr[1] = 0;
			arr[0]++;
		}
	}
	cout << cnt << endl;
}
