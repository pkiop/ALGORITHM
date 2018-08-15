#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <cstring>

using namespace std;

typedef long long ll;

int n, capacity;
int volume[100], need[100];
int cache[1001][100];
string name[100];
//캐리어에 남은 용량이 capacity일 때, item 이후의 물건들을 
//담아 얻을 수 있는 최대 절박도의 합을 반환한다.
int pack(int capacity, int item) {
	//기저사례 : 더 담을 물건이 없을 때
	if (item == n) return 0;
	int& ret = cache[capacity][item];
	if (ret != -1) return ret;
	// 이 물건을 담지 않을 경우
	ret = pack(capacity, item + 1);
	// 이 물건을 담을 경우
	if (capacity >= volume[item])
		ret = max(ret, pack(capacity - volume[item], item + 1) + need[item]);
	return ret;
}

void reconstruct(int capacity, int item, vector<string>& picked) {
	if (item == n) return;
	if (pack(capacity, item) == pack(capacity, item + 1)) {
		reconstruct(capacity, item + 1, picked);
	}
	else {
		picked.push_back(name[item]);
		reconstruct(capacity - volume[item], item + 1, picked);
	}
}

int main(void) {
	int t;
	cin >> t;
	while (t--) {
		memset(cache, -1, sizeof(cache));

		cin >> n >> capacity;
		for (int i = 0; i < n; ++i) {
			cin >> name[i] >> volume[i] >> need[i];
		}
		pack(capacity, 0);
		vector<string> ans;
		reconstruct(capacity, 0, ans);
		int cnt = 0;
		int len = ans.size();
		for (int j = 0; j < len; ++j) {
			for (int i = 0; i < 100; ++i) {
				if (ans[j] == name[i]) {
					cnt += need[i];
					break;
				}
			}
		}
		cout << cnt << ' ' << len << endl;
		for (int i = 0; i < len; ++i) {
			cout << ans[i] << endl;
		}
	}
	return 0;
}

