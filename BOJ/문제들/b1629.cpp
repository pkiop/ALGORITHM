#include <iostream>

using namespace std;

typedef long long ll;
ll pow(ll a, ll n, ll c) {
	if(n == 0)
		return 1;
	if(n == 1)
		return a;
	ll temp = pow(a, n/2, c); 
	if(n%2 == 0) {
		return ((temp * temp) % c);
	}
	else {
		return ((temp * temp)%c * a) %c;
	}
}

int main(void) {
	int a,b,c;
	freopen("input.txt", "r", stdin);
	cin >> a >> b >> c;
	cout << pow(a%c, b, c);
	return 0;

}
