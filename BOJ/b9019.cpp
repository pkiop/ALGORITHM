#include <iostream>
#include <vector>
#include <queue>
#include <stack>
#include <algorithm>
#include <fstream>
#include <string>
#include <cstring>
#include <map>

#define pii pair<int, int>
#define pli pair<long, int>
#define pbs pair<bool,string>
#define mii map<int, int>
#define msi map<string, int>

typedef unsigned long long ull;
typedef long long ll;

using namespace std;



#define GO
#define DEBUG


/*

5 21
-3 2 -4 -1 -5

*/
int first, second;
bool visited[10000];
char ch[10000];
int before[10000];
queue<int> q;


void go(int in) {
	memset(visited, false, sizeof(visited));
	memset(before, -1, sizeof(visited));
	memset(ch, -1, sizeof(ch));
	q.push(in);
	visited[in] = true;
	while (!q.empty()) {
		int n = q.front();
		q.pop();
		if (n == second) {
			break;
		}
		//cout << n << endl;
		int a, b, c, d;
		a = n / 1000;
		b = (n - a * 1000) / 100;
		c = (n - a * 1000 - b * 100) / 10;
		d = n % 10;
		//cout << a << ' ' << b << ' ' << c << ' ' << d << endl;
		int temp;


		//D
		temp = (n * 2) % 10000;
		if (!visited[temp]) {
			ch[temp] = 'D';
			before[temp] = n;
			visited[temp] = true;
			q.push(temp);
		}
		

		//S
		temp = (n == 0 ? 9999 : n - 1);
		if (!visited[temp]) {
			ch[temp] = 'S';
			before[temp] = n;
			visited[temp] = true;
			q.push(temp);
		}

		//L
		
		temp = b * 1000 + c * 100 + d * 10 + a;
		if (!visited[temp]) {
			ch[temp] = 'L';
			before[temp] = n;
			visited[temp] = true;
			q.push(temp);
		}

		//R
		temp = d * 1000 + a * 100 + b * 10 + c;
		if (!visited[temp]) {
			ch[temp] = 'R';
			before[temp] = n;
			visited[temp] = true;
			q.push(temp);
		}

	}

	while (!q.empty()) {
		q.pop();
	}



}

int main(void) {

#ifdef GO
	freopen("input.txt", "r", stdin);
#endif
	//ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	int t;
	cin >> t;
	while (t--) {

		cin >> first >> second;
		go(first);
		vector<char> ans;
		int idx = second;
		while (idx != first) {
			ans.push_back(ch[idx]);
			idx = before[idx];
		}
		int len = ans.size();
		for (int i = len - 1; i >= 0; --i) {
			cout << ans[i];
		}
		cout << '\n';
	}











#ifdef GO
	cout << "\nerase go\n";
#endif

	return 0;
}