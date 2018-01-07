#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;



////////////////operator function 정의///////////////////////
/*struct xy {
	int x;
	int y;
	bool operator<(const xy& v) {
		if (x > v.x) {
			return false;
		}
		else if (x == v.x) {
			if (y > v.y) {
				return false;
			}
		}
		return true;
	}
};
*/
/////////////////////////////////////////////



///////////////////cmp 정의////////////////////

/*struct xy {
	int x;
	int y;
};*/

/*bool cmp(const xy& u, const xy& v) {
	if (u.x > v.y) {
		return false;
	}
	else if (u.x == v.y) {
		if (u.y > v.y)
			return false;
	}
	return true;
}*/

struct xy {
	int x;
	int y;
};
int main() {

	int n;
	cin >> n;
	xy ans[100001];
	for (int i = 0; i < n; ++i) {
		cin >> ans[i].x >> ans[i].y;
	}
	sort(ans, ans + n, []( const xy& u, const xy& v){
			if (u.x < v.x) 
				return true;
			else if (u.x == v.x) 
				if (u.y < v.y) 
					return true;
			return false;
	});
		for (int i = 0; i < n; ++i) {
			cout << ans[i].x << ' ' << ans[i].y << '\n';
	}

	////////////////operator function 정의///////////////////////
	/*int n;
	cin >> n;
	xy ans[100001];
	for (int i = 0; i < n; ++i) {
		cin >> ans[i].x >> ans[i].y;
	}
	sort(ans, ans+n);
	for (int i = 0; i < n; ++i) {
		cout << ans[i].x << ' ' << ans[i].y << '\n';
	}*/
	////////////////////////////////////////////////////////////////



	///////////////////cmp 정의////////////////////
	/*int n;
	cin >> n;
	struct xy ans[100001];
	for (int i = 0; i < n; ++i) {
		cin >> ans[i].x >> ans[i].y;
	}
	sort(ans, ans + n, cmp);
	for (int i = 0; i < n; ++i) {
		cout << ans[i].x << ' ' << ans[i].y << '\n';
	}*/
	//////////////////////////////////////////////

	//////////////////vector로 쉽게 풀기 //////////////////

	/*vector<pair<int,int>> ans;
	int n;
	cin >> n;
	for(int i=0;i<n;++i){
		int x,y;
		cin >> x >> y;
		ans.push_back(make_pair(x,y));
	}
	sort(ans.begin(), ans.end());
	for (int i = 0; i < n; ++i) {
		cout << ans[i].first << ' ' << ans[i].second << '\n';
	}*/

	/////////////////////////////////////////////////////
	return 0; 
}