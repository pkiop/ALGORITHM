#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <cstring>
#include <stack>
#include <queue>
#include <limits.h>

using namespace std;

typedef unsigned long long ull;
typedef long long ll;

int n;
int tb1[200001];

int main(void){
	cin >> n;
	ll sum = 0;
	for(int i=0;i<n;++i){
		cin >> tb1[i];
		sum += tb1[i];
	}
	ll tempsum = 0;
	for(int i=0;i<n;++i){
		tempsum += tb1[i];
		if(sum/2 <= tempsum){
			cout << i+1 << endl;
			return 0;
		}
	}

	return 0;
}
