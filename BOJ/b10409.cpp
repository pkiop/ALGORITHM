#include <iostream>

using namespace std;

int main(void)
{
	int n, min,sum=0;
	cin >> n >> min;
	int i,a;
	for (i = 0; i<n&&cin >> a && sum + a <= min; ++i)
		sum += a;
	cout << i;
	return 0;

}
