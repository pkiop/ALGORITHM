#include <iostream>
#include <string>

using namespace std;

const int mod = 1234567891;
long long retpow(int i) {
	long long ret = 1;
	for(int j=0;j<i;++j) {
		ret = (ret * 31) % mod;
	}
	return ret;
}

int main(void) {
	int n;
	string s;
	cin >> n >> s;
	long long ans = 0;
	long long temp;
	for (int i = 0; i < n; ++i)
	{
		temp = ((s[i] - 'a') + 1) * retpow(i) % mod;
		ans += temp;
		ans = ans % mod;
	}
	cout << ans << endl;
	return 0;
}
