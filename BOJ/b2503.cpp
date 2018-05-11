#include <iostream>
#include <string>
#include <vector>
#include <math.h>

using namespace std;

int n;
int ans = 0;

int pickslo(int pick, int index) {
	//cout << "pickso" << endl;
	if (index == 0) {
		return pick / 100;
	}
	if (index == 1) {
		return (pick / 10) % 10;
	}
	if (index == 2) {
		return pick % 10;
	}
}

int nextpic(int pick) {
	int nextp = pick;
	while (1) {
		nextp++;
		//cout << "first " << nextp << endl;
		int a = nextp / 100;
		int b = nextp / 10 % 10;
		int c = nextp % 10;
		//cout << "second : " << a << b << c << endl;
		if (a != b && b != c && c != a && a!=0 && b!=0 && c!=0) {
			break;
		}

	}
	
	return nextp;
}

void go(vector<string>& num, vector<int>& st, vector<int>& ba, int pick) {
	int strike = 0;
	int ball = 0;
	//cout << pick << endl;
	if (pick > 999) {
		return;
	}
	int pass=0;
	for (int fall = 0; fall < n; ++fall) {
		
		//cout << num[fall] << " " << pick << endl;
		for (int fp = 0; fp < 3; ++fp) {
			for (int fn = 0; fn < 3; ++fn) {
				//cout << "num : " <<num[fall][fn] << " pick : " << char(pickslo(pick, fp) + '0') << endl;
				if (fp == fn && num[fall][fn] == char(pickslo(pick, fp) + '0')) {
					strike++;
				}
				if (fp != fn && num[fall][fn] == char(pickslo(pick, fp) + '0')) {
					ball++;
				}
			}
		}
		//cout << "본래 pair : " << st[fall] << ' ' << ba[fall] << " 만든 fair" << strike << ' ' << ball << endl;
		if (st[fall] == strike && ba[fall] == ball) {
			pass++;
		}
		else { 
			break; 
		}
		strike = 0;
		ball = 0;
	}
	
	if (pass == n) {
		
		ans++;
		
	}
	go(num, st, ba, nextpic(pick));
}

int main(void) {

	cin >> n;
	vector<string> num(n);
	vector<int> st(n);
	vector<int> ba(n);
	for (int i = 0; i < n; ++i) {
		cin >> num[i];
		cin >> st[i];
		cin >> ba[i];
	}
	go(num, st, ba, 123);
	cout << ans << endl;
	return 0;
}
