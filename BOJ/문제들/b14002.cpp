#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <cstring>

using namespace std;

typedef long long ll;

int n;
int cache[1000001], S[1000001], choices[1000001];

int lis4(int start) {
	int& ret = cache[start + 1];
	if (ret != -1) return ret;
	//항상 S[start]는 있기 때문에 길이는 최하 1
	ret = 1;
	int bestNext = -1;
	for(int next = start+1; next < n;++next)
		if (start == -1 || S[start] < S[next]) {
			int cand = lis4(next) + 1;
			if (cand > ret) {
				ret = cand;
				bestNext = next;
			}
		}
	choices[start + 1] = bestNext;
	return ret;
}

void reconstruct(int start, vector<int>& seq) {
	if (start != -1) seq.push_back(S[start]);
	int next = choices[start + 1];
	if (next != -1) reconstruct(next, seq);
}


int main(void) {
	memset(cache, -1, sizeof(cache));
	cin >> n;
	for (int i = 0; i < n; ++i) {
		cin >> S[i];
	}
	lis4(-1);
	
	vector<int> ans;
	reconstruct(-1, ans);
	cout << ans.size() << endl;
	for (int i = 0; i < ans.size()-1; ++i) {
		cout << ans[i] << ' ';
	}
	cout << ans[ans.size() - 1];
	return 0;
}