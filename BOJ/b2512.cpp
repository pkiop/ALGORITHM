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
int tb1[100001];
int tb2[1001][1001];
int che2[1001][1001];
ull che1[100001];

ull go(int idx, int sum){
	
}

int main(void){
	//input
	cin >> n;
	for(int i=0;i<n;++i){
		cin >> tb1[i];
	}
	int total;
	cin >> total;


	//no exceed case
	int tmp = total;
	int max_money = 0;

	//cal maxmoney
	for(int i=0;i<n;++i){
		tmp -= tb1[i]; // 예산이 충분한지 
		max_money = tb1[i] > max_money ? tb1[i] : max_money;
	}

	if(tmp >= 0){ // 예산이 충분하면 가장 큰 돈을 출력
		return cout << max_money, 0;
	}



	//BS phase
	//적당한 예산을 구하는 과정이다. 우선 절반값으로 둔다.
	int left = total/n;
	int right = max_money;

	while(left<=right){
		int mid = (left + right) / 2;
		tmp = total;

		for(int i=0;i<n;++i){
			if(mid>=tb1[i]) tmp -= tb1[i];
			else tmp -= mid;
		}
		if(tmp>=0) left = mid + 1;
		else right = mid - 1;
	}
	cout << right;

	return 0;
}


// while(left<=right){
// 		int mid = (left+right) / 2; // 새로 설정한 예산한도
// 		tmp = total;

// 		for(int i=0;i<n;++i){
// 			if(mid >= tb1[i]) tmp -= tb1[i]; // 예산한도 아래면 그대로
// 			else tmp -= mid; // 초과면 예산한도 만큼
// 		}
// 		if(tmp >= 0) left = mid+1; // 예산초과하지 않았다. 
// 		else right = mid - 1; // 초과했다. 
// 	}
// 	cout << right;