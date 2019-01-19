#include <iostream>
#include <algorithm>
#include <cstring>
#include <string>
#include <limits.h>
#include <queue>
#include <stack>

using namespace std;

int tb1[100001];
int che[100001];
bool doo[100001];
int n, m;

int main(void)
{
	int t;
	cin >> t;
	int a = 0;
	int b = 1;
	int apik = 1;
	bool aup = true;
	int bpik = 2;
	bool bup = false;
	while(t--){
		if(aup){
			a++;
		}
		else{
			a--;
		}
		if(bup){
			b++;
		}
		else{
			b--;
		}
		if(apik == a){
			apik = a+2;
			aup = false;
		}
		if(bpik == b){
			bpik = b+2;
			bup = false;
		}
		if(a == 0 && aup == false){
			aup = true;
			a = 1;
		}
		if(b == 0 && bup == false){
			bup = true;
			b = 1;
		}
		//cout << b << ' ';
	}

	cout << a << '/' << b;

	return 0;
}