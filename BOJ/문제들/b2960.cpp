#include <iostream>
#include <queue>
#include <map>
#include <algorithm>
#include <string>
using namespace std;


bool c[300000];
int n = 123457*2;


bool ch[1001];
int main(void) {
	
	int a, b;
	cin >> a >> b;
	int cnt = 0;
	for (int i = 2; i <= a; ++i) {
		if(ch[i] == false)
			for (int j = i; j <= a; j += i) {
				if (ch[j] == false) {
					ch[j] = true;
					cnt++;
					if (cnt == b) {
						cout << j;
						return 0;
					}
				}
			}
	}
	return 0;
}