#include <iostream>
#include <algorithm>

using namespace std;

bool cake[1001];
int man[1001];
int main(void) {
	int L, M;
	cin >> L >> M;
	int max_idx;
	int now_max_cnt = 0 ; 

	int a,b;
	for(int i=1;i<=M;++i) {
		cin >> a >> b;
		if(b - a > now_max_cnt) {
			max_idx = i;
			now_max_cnt = b - a;
		}

		for(int j=a;j<=b;++j) {
			if(cake[j] == false) {
				cake[j] = true;
				man[i]++;
			}
		}
	}
	int smax_idx;
	int now_man_x = 0;
	for(int i=1;i<=M;++i) {
		if(man[i] > now_man_x) {
			now_man_x = man[i];
			smax_idx = i;
		}
	}
	cout << max_idx << '\n' << smax_idx << endl;
	return 0;
}
