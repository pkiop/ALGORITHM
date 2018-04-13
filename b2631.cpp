// boj 2631 줄세우기 

#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <cstring>
#include <stack>
#include <queue>
#include <limits.h>

using namespace std;

typedef long long ull;

int n;
int p[100001];
ull d[100001];

int main(void){

	cin >> n;
	for(int i=1;i<=n;++i){
		cin >> p[i];
	}
	for (int i = 1; i <= n; ++i) {
		d[i] = 1;
		for (int j = 1; j < i; ++j) {
			if (p[i] > p[j] && d[i] < d[j] + 1)
				d[i] = d[j] + 1;
		}
	}

	int max = -1;
	for (int i = 1; i <= n; ++i)
		if (max < d[i])
			max = d[i];

	cout << n - max << endl;
	
	return 0;
}
