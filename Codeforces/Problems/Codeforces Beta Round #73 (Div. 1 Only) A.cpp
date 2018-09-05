#include <iostream>
#include <cstdio>
#include <string>
#include <vector>
#include <algorithm>
#include <cstring>
#include <cassert>

using namespace std;

int gcd(int a, int b) {
	while (b != 0) {
		int r = a % b;
		a = b;
		b = r;
	}
	return a;
}

int lcm(int a, int b) {
	return a * b / gcd(a, b);
}

int main(void) {
	int a, b;
	cin >> a >> b;
	int LCM = lcm(a, b);
	int cnt = 1;
	int cnt_a = 0;
	int cnt_b = 0;
	//cout << "LCM = " << LCM << endl;
	for (int i = 1; i <= LCM; ++i) {
		//cout << "i = " << i << ' ' << "cnt = " << cnt << endl;
		if (i%a == 0 && i%b == 0) {
			if (cnt_a < cnt_b) {
				cnt_a += cnt;
			}
			else if (cnt_a > cnt_b) {
				cnt_b += cnt;
			}
			else {
				if (a >= b) {
					cnt_a += cnt;
				}
				else {
					cnt_b += cnt;
				}
			}
			cnt = 0;
		}
		else if (i%a == 0) {
			//cout << "cnt_a up => " << cnt << endl;
			cnt_a += cnt;
			cnt = 0;
		}
		else if (i%b == 0) {
			//cout << "cnt_b up => " << cnt << endl;
			cnt_b += cnt;
			cnt = 0;
		}
		cnt++;
	}
	//cout << "cnt_a = " << cnt_a << ' ' << "cnt_b = " << cnt_b << endl;
	if (cnt_a == cnt_b) {
		cout << "Equal" << endl;
		return 0;
	}
	cout << (cnt_a > cnt_b ? "Dasha" : "Masha");
	return 0;

}