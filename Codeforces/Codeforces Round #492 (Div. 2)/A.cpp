#include <iostream>

using namespace std;

int arr[] = { 1,5,10,20,100 };
int main(void) {
	int n;
	cin >> n;
	int cnt = 0;
	for (int i = 4; i >= 0; --i) {
		while (n >= arr[i]) {
			n -= arr[i];
			cnt++;
		}
	}
	cout << cnt << endl;
	return 0;
}