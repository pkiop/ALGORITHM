#include <iostream>
#include <algorithm>

using namespace std;

int arr[1001];
int main(void) {
	int n;
	cin >> n;
	for(int i=0;i<n;++i) {
		cin >> arr[i];	
	}
	sort(arr, arr+n);
	if(arr[0] != 1) {
		cout << 1 << endl;
	}
	else {
		int sum = 1;
		for(int i=1;i<n;++i) {
			if(arr[i] > sum + 1) {
				break;
			}
			sum += arr[i];
		}			
		cout << sum + 1 << endl;
	}
	return 0;

}
