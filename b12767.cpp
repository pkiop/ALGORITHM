#include <iostream>
#include <vector>
#include <set>

using namespace std;

struct Node {
	int val;
	Node *left;
	Node *right;
	Node() {
		val = 0;
		left = NULL;
		right = NULL;
	}
};

string preorder(Node *root) {
	string ans = "";
	//V는 방문하지 않은 노드를 방문할 때 쓰는 check
	ans += "V"; 
	if (root->left) {
		//L은 left방문하지 않았을 때 방문하면서 ch
		ans += "L";
		ans += preorder(root->left);
		//l은 방문한 노드를 방문할 때 쓰는 ch
		ans += "l";
	}
	if (root->right) {
		ans += "R";
		ans += preorder(root->right);
		ans += "r";
	}
	//방문한 노드를 방문할때 쓰는 v
	ans += "v";
	return ans;
}

void remove(Node *root) {
	//root의 왼쪽자식이 있으면 그것부터 지우러간다.
	if (root->left) {
		remove(root->left);
	}
	if (root->right) {
		remove(root->right);
	}
	delete root;
}

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int n, m;
	cin >> n >> m;
	set<string> s;
	for (int k = 0; k < n; ++k) {
		vector<int> a(m);
		for (int i = 0; i < m; ++i) {
			cin >> a[i];
		}
		Node *root = new Node;
		root->val = a[0];
		for (int i = 1; i < m; ++i) {
			Node *cur = root;
			while (true) {
				// 비교하는 값보다 노드가 더 크면 왼쪽에 넣어야 한다.
				if (cur->val > a[i]) {
					//왼쪽에 넣어야하는데 비었으면 그자리가 자기자리다. 
					if (cur->left == NULL) {
						cur->left = new Node;
						cur->left->val = a[i];
						break;
					}
					//그렇지 않다면 왼쪽으로 계속 탐색한다. 
					else {
						cur = cur->left;
					}
				}
				else if (cur->val < a[i]) {
					if (cur->right == NULL) {
						cur->right = new Node;
						cur->right->val = a[i];
						break;
					}
					else {
						cur = cur->right;
					}
				}
				else {
					break;
				}
			}
		}
		s.insert(preorder(root));
		remove(root);
	}
	cout << s.size() << '\n';
	return 0;
}