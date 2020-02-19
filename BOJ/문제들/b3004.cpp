#include <iostream>

using namespace std;

int main(void) {
	int n;
	cin >> n;
	int ans = 0;
	int plus = 2;
	int on = 0;
	
	
	while(n--) {
		ans += plus;
		if(on == 2){
			plus++;
			on = 1;
		}
		else {
			on++;
		}
	}
	cout << ans << endl;
}
