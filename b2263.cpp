#include <iostream>
#include <algorithm>

using namespace std;

int in[100001];
int post[100001];
int position[100001];
int n;
void go(int is,int ie,int ps,int pe){
	
	if(is > ie || ps > pe) return;

	int root = post[pe];
	cout << root << ' ';

	int ir = position[root];
	int l = ir - is;

	go(is,ir-1,ps,l+ps-1);
	go(ir+1,ie,ps + l,pe-1);

}

int main(void)
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cin >> n;
	for(int i=0;i<n;++i){
		cin >> in[i];
	}
	for(int i=0;i<n;++i){
		cin >> post[i];
	}
	for(int i=0;i<n;++i){
		position[in[i]] = i;
	}
	go(0,n-1,0,n-1);
	return 0;
}