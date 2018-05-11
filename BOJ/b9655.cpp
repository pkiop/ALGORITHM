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

//1 SK
//2 CY
//3 SK
//4 CY
//5 SK
//6 CY
//7

int main(void){
	cin >> n;
	if(n%2==0){
		cout << "CY" << endl;
	}
	else{
		cout << "SK" << endl;	
	}

	return 0;
}
