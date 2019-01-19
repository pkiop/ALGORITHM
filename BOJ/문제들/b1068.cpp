#include <iostream>
#include <vector>
#include <algorithm>
#include <stack>

using namespace std;

vector<int> tree[10001];

int cut_node;

int go(int root) {
	if (root == cut_node) {
		return 0;
	}
	int len = tree[root].size();

	if (len == 0) {
		return 1;
	}

	int ret = 0;
	for (int i = 0; i < len; ++i) {
		if (tree[root][i] == cut_node) {
			if (len == 1) {
				ret = 1;
			}
		}
		ret += go(tree[root][i]);
		
	}
	return ret;
}

int main(void) {
	int n;
	cin >> n;
	// 트리생성 
	int temp;
	int root = 0;
	for (int i = 0; i < n; ++i) {
		cin >> temp;
		if (temp == -1) {
			root = i;
		}
		else {
			tree[temp].push_back(i);
		}
	}
	cin >> cut_node;	
	cout << go(root) << endl;
	
	return 0;
}