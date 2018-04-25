#include <iostream>

using namespace std;

int go(int a,int b){
	int sum = 0;
	if(a==0){
		return b;
	}
	for(int i=1;i<=b;++i){
		sum += go(a-1,i);
	}
	return sum;
}

int main(void){
	int t;
	cin >> t;
	while(t--){
		int a, b;
		cin >> a >> b;
		cout << go(a,b) << '\n';
	}
	return 0;
}