#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;

int cache2[1001][1001];
int n, m;

int climb(int days, int climbed) {
	// m일 까지 왔을 떄 올라온 높이가 n보다 큰가?
	//cout << days << " m " <<m <<endl;
	if (days == m) return climbed >= n ? 1.0 : 0.0;

	int& ret = cache2[days][climbed];

	if (ret != -1.0) return ret;
	//이 아래의 return 문이 2^n개의 경우의 수를 다 만들어 준다. 
	return ret = climb(days + 1, climbed + 1) + climb(days + 1, climbed + 2);
}

int main(void)
{
	cin >> n >> m;
	cout << climb(0, 0) / pow(2,n) << endl;
	
	return 0;
}