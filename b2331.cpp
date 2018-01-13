#include <iostream>

using namespace std;


int ch[1000001];

int main(){
	int a,p;
	cin >> a >> p;
	int cnt = 0;
	while(ch[a]==0){
		cout << "a : " << a << '\n';
		ch[a] = ++cnt;
		int sum = 0;
		while(a>0){
			int mul = 1;
			for(int i=0;i<p;++i){
				mul*=a%10;
			}
			sum += mul;
			a/=10;
		}
		a = sum;
	}
	cout << a << '\n';
	cout << ch[a]-1;
	return 0;
}
