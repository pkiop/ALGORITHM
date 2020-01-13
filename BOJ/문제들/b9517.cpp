#include <iostream>

using namespace std;

int main(void) {
	int nb, m;

	cin >> nb >> m;
	int a;
	char b;

	int timer = 210;
	for(int i=0;i<m;++i) {
		cin >> a >> b;
		timer -= a;
		if(timer <= 0) {
			cout << nb << endl;
			break;
		}

		if(b == 'T') {
			nb++;
			if(nb == 9) {
				nb = 1;
			}
		}		
	}
		
	return 0;
}
