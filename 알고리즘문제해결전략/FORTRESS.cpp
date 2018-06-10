#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <cstring>
using namespace std;

int n;
int y[100], x[100], radius[100];

int sqr(int x) {
	return x * x;
}

int sqrdist(int a, int b) {
	return sqr(y[a] - y[b]) + sqr(x[a] - x[b]);
}

bool encloses(int a, int b) {
	return radius[a] > radius[b] && sqrdist(a, b) < sqr(radius[a] - radius[b]);
}

bool isChild(int parent, int child) {
	if (!encloses(parent, child)) return false;
	for (int i = 0; i < n; ++i) {
		if (i != parent && i != child && encloses(parent, i) && encloses(i, child))
			return false;
	}
	return true;
}

struct TreeNode {
	vector<TreeNode*> child;
};

TreeNode* getTree(int root)// 첫번째 주어진 값이 외벽이므로 root를 구하는 걱정은 안해도 된다. 
{
	TreeNode* ret = new TreeNode();
	for (int ch = 0; ch < n; ++ch) {
		if (isChild(root, ch))
			ret->child.push_back(getTree(ch));
	}
	return ret;
}

int longest;
vector<int> heights;
int height(TreeNode* root) {
	vector<int> heights;
	for (int i = 0; i < root->child.size(); ++i)
		heights.push_back(height(root->child[i]));
	if (heights.empty()) return 0;
	sort(heights.begin(), heights.end());

	if (heights.size() >= 2)
		longest = max(longest, 2 + heights[heights.size() - 2] + heights[heights.size() - 1]);
	return heights.back() + 1;

}

int solve(TreeNode* root) {
	longest = 0;
	int h = height(root);
	return max(longest, h);
}

int main(void) {
	int t;
	cin >> t;
	while (t--) {
		cin >> n;
		memset(y, 0, sizeof(y));
		memset(x, 0, sizeof(x));
		memset(radius, 0, sizeof(radius));

		for (int i = 0; i < n; ++i) {
			cin >> y[i];
			cin >> x[i];
			cin >> radius[i];
		}
		TreeNode* tr = getTree(0);
		cout << solve(tr) << endl;
	}
	return 0;
}