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
	long long a, b, c;
	int temp = 0;
	cin >> a >> b >> c;
	
	cout << (c-b -1) / (a-b) + 1;
	return 0;
}