#include <iostream>

using namespace std;

typedef long long ll;

int n,m;
int tb1[100001];
int main(void)
{
	cin >> n >> m;
	for(int i=0;i<m;++i){
		cin >> tb1[i];
	}
	if(n<=m){
		cout << n << endl;
		return 0;
	}
	ll left = 0;
	ll right = 2000000000LL * 1000000LL ;
	ll mid;
	while(left <= right){
		mid = (left + right) / 2;
		//cout << mid << endl;

		ll st_cnt = 0;
		ll st_cnt_minp = 0;
		st_cnt = m;
		for(int i=0;i<m;++i){
			st_cnt += mid / tb1[i];
		}
		st_cnt_minp = st_cnt;
		for(int i=0;i<m;++i){
			if(mid % tb1[i] == 0){
				st_cnt_minp--;
			}
		}	
		
		st_cnt_minp++;
		if(n > st_cnt){
			left = mid + 1;
			
		}
		else if(n < st_cnt_minp){
			right = mid - 1;
		}
		else{
			for(int i=0;i<m;++i){
				if(mid % tb1[i] == 0){
					if(n == st_cnt_minp){
						cout << i+1;
						return 0;
					}
					st_cnt_minp++;
				}
			}
		}
	}
	return 0;
}