#include <iostream>

using namespace std;

void go(int n,int x,int y){
	if(n == 0)
		return;
	go(n-1,x,6-x-y);
	cout << x << ' ' << y << '\n';
	go(n-1,6-x-y,y);
}

int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int n;
	cin >> n;
	cout << (1<<n) - 1 << endl;
	go(n,1,3); // 1번에서 3번으로 n개를 옮긴다. 
	return 0;
}