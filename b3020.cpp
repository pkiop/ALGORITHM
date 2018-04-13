#include <iostream>
#include <algorithm>
#include <cstring>
 
using namespace std;
 
const int err = -99999999;
int up[100001]; // 종유석
int dn[100001]; // 석순

int n,h;

int upc(int tph){ // temp h 
	int left = 0;
	int right = n/2-1;
	while(left <= right){
		int mid = (left + right) / 2;
		if(up[mid] >= tph){
			right = mid - 1;
		}
		else{
			left = mid + 1;
		}
	}
	return n / 2 - left;
}

int dnc(int tph){
	int left = 0;
	int right = n/2-1;
	while(left <= right){
		int mid = (left + right) / 2;
		if(dn[mid] >= tph){
			right = mid - 1;
		}
		else{
			left = mid + 1;
		}
	}
	return n/2 - left;
}

int main(void)
{
	cin >> n >> h;
	for(int i=0;i<n/2;++i){
	 	cin >> up[i];
	 	cin >> dn[i];
	}

	sort(up,up+n/2);
	sort(dn,dn+n/2);

	int minval = 999999;
	int mincnt = 1;
	for(int i=1;i<=h;++i){
		int temp = upc(i) + dnc(h - i + 1);
		if(temp == minval){
			mincnt++;
		}else if(temp < minval){
			mincnt = 1;
			minval = temp;
		}
	}
	cout << minval << ' ' << mincnt <<  endl;
	return 0;

}

 
