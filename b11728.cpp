#include <iostream>

using namespace std;

int a[1000001];
int b[1000001];
int c[1000001];

int main(void){
	int n1,n2;
	cin >> n1 >> n2;
	for(int i=0;i<n1;++i){
		cin >> a[i];
	}
	for(int i=0;i<n2;++i){
		cin >> b[i];
	}
	int start = 0;
	int end = n1+n2-1;
	int mid = (start + end) / 2;
	int k=0;
	int i = 0;
	int j = 0;
	while(i < n1 && j < n2){
		if(a[i] < b[j]){
			c[k++] = a[i++];
		}
		else{
			c[k++] = b[j++];
		}
	}
	while(i<n1) c[k++] = a[i++];
	while(j<n2) c[k++] = b[j++];

	for(int i=0;i<k;++i){
		cout << c[i] << ' ';
	}
	return 0;
}