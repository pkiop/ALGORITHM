#include <iostream>
#include <queue>
#include <map>
#include <algorithm>
#include <string>
using namespace std;


bool c[300000];
int n = 123457*2;
void cal_prime_num() {
	for (int i = 2; i <= n; ++i) {
		if (c[i] == false) {
			for (int j = i * 2; j <= n; j += i) {
				//이론상으로는 j=i*i가 맞으나 정수 오버플로우가 발생할 수 있음.
				//j*2를 하면 이미 지웠던 것을 또 지우게 되지만 문제는 없으므로.
				c[j] = true;
			}
		}
	}
}


int main(void) {
	
	cal_prime_num();
	int t = -1;
	cin >> t;
	int cnt;
	while (t!=0) {
		cnt = 0;
		for (int i = t+1; i <= 2*t; ++i) {
			if (c[i] == false) {
				cnt++;
			}
		}
		cout << cnt << '\n';
		cin >> t;
	}


	return 0;
}