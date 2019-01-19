#include <iostream>
#include <list>
#include <algorithm>

using namespace std;

int main(void)
{
	int n, m;
	cin >> n >> m;
	list<int> nums;
	for (int i = 1; i <= n; ++i) {
		nums.push_back(i);
	}
	list<int> ans;
	list<int>::iterator it;
	it = nums.begin();
	int cnt = 1;
	while (!nums.empty()) {
		if (cnt == m) {
			ans.push_back(*it);
			it++; // 다음 노드로 가기전에 remove를 하면 다음 노드로 갈 수 없다. 

			nums.remove(ans.back());
			cnt = 1;
		}
		else {
			cnt++;
			it++;

		}

		if (it == nums.end()) {
			it = nums.begin();
		}
	}
	int last_num = ans.back();
	ans.pop_back();
	cout << "<";
	for (it = ans.begin(); it != ans.end(); ++it) {
		cout << *it << ", ";
	}
	cout << last_num << ">" << endl;
	return 0;
	
}