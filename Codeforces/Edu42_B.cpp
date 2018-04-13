#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int main(void)
{
	int k, a, b;
	cin >> k >> a >> b;
	string s;
	cin >> s;
	if(a<b){ // a is big num
		swap(a,b);
	}

	int len = s.size();
	bool aon = false;
	bool bon = false;
	int ans = 0;
	for(int i=0;i<len;++i){
		if(s[i] == '*'){
			aon = false;
			bon = false;
			if(a<b){ // a is big num
				swap(a,b);
			}
		}
		else{
			if(!aon && a>0){
				ans++;
				a--;
				aon = true;
				bon = false;
			}
			else if(!bon && b>0){
				ans++;
				b--;
				bon = true;
				aon = false;
			}
			else{
				bon = false;
				aon = false;
				if(a<b){ // a is big num
					swap(a,b);
				}
			}
		}
		if(a ==0 && b == 0){
			break;
		}
	}
	cout << ans << endl;
	return 0;

}