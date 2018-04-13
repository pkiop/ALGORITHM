#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <cstring>

using namespace std;
typedef long long ll;
ll n;
const int mod = 15746;

ll che[3];
int mche[3][3];

int main(void)
{
	cin >> n;
	che[0] = 1;
	che[1] = 1;
	for (int i = 0; i <n-1; ++i) {
		che[2] = (che[0] % mod + che[1] % mod) % mod;
		che[0] = che[1];
		che[1] = che[2];
	}
	cout << che[2]%mod;


	return 0;
}
