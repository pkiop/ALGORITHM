#include <iostream>
#include <vector>
#include <queue>
#include <stack>
#include <algorithm>
#include <fstream>
#include <string>
#include <cstring>
#include <map>
#include <set>

#define pii pair<int, int>
#define pli pair<long, int>
#define mii map<int, int>
#define msi map<string, int>

typedef unsigned long long ull;
typedef long long ll;

using namespace std;



#define GO
#define DEBUG


/*
c가 1개인데 다른게 2개면 fail 


*/
int arr[5]; // c r o a k 나온 횟수 count

int main(void) {
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#ifdef GO
	freopen("input.txt", "r", stdin);
#endif

	int n;
	cin >> n;
	for(int test = 1;test <= n ; ++test){
		string s;
		memset(arr, 0, sizeof(arr));
		cin >> s;
		int ret = 0;
		int len = s.size();
		for (int i = 0; i < len; ++i) {
			if (s[i] == 'c') {
				arr[0]++;
			}
			if (s[i] == 'r') {
				if (arr[1] >= arr[0])
					ret = 9999;
				arr[1]++;
			}
			if (s[i] == 'o') {
				for (int j = 0; j < 2; ++j)
					if (arr[2] >= arr[j])
						ret = 9999;
				arr[2]++;
			}
			if (s[i] == 'a') {
				for (int j = 0; j < 3; ++j)
					if (arr[3] >= arr[j])
						ret = 9999;
				arr[3]++;
			}
			if (ret == 9999) {
				break;
			}
			if (s[i] == 'k') {

				for (int j = 0; j < 4; ++j) {
					if (arr[j] == 0) {
						ret = 9999;
						break;
					}
					ret = max(arr[j], ret);
					arr[j]--;
				}
			}
			
		}
		for (int i = 0; i < 4; ++i) {
			if (arr[i] != 0) {
				ret = 9999;
				break;
			}
		}
		cout << '#' << test << ' ';
		if (ret == 9999) {
			cout << -1 << endl;
		}
		else {
			cout << ret << endl;
		}
	}
















#ifdef GO
	cout << "\nerase go\n";
#endif

	return 0;
}