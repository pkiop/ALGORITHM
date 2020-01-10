#include <iostream>

using namespace std;

int main(void) {
	
	int n;
	cin >> n;

	int up = 0;
	int down = 0;
	int sum = 0;
	while(1) {
		sum += up;
		sum += down;
		if(up == n) {
			break;
		}
		if(up == down) {
			up = 0;
			down++;
		}
		else if(up < down) {
			up++;
		}
	}
	cout << sum << endl;

	return 0;
}
