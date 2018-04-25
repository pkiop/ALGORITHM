#include <iostream>
#include <string>
#include <limits>
using namespace std;

int main(void)
{
	int n;
	cin >> n;
	int temp = 0;
	for(int i=0;i<n;++i){
		string s;
		int t;
		if(s == "add"){
			cin >> t;
			temp | (1<<t);
		}
		if(s == "check"){
			cin >> t;
			int tempv;
			if(temp & (1<<t) == 1){
				tempv = 1;
			}
			else{
				tempv = 0;
			}
			cout << tempv << endl;
		}
		if(s == "remove"){
			cin >> t;
			temp & ~(1<<t);
		}
		if(s == "toggle"){
			cin >> t;
			temp ^ (1<<t);
		}
		if(s == "empty"){
			temp = 0;
		}
		if(s == "all"){
			temp = INT32_MAX;
		}
	}
}