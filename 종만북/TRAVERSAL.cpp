#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

vector<int> slice(const vector<int>& v, int a, int b) {
	return vector<int>(v.begin() + a, v.begin() + b);
}

void printPostOrder(const vector<int>& preorder, const vector<int>& inorder) {
	//트리에 포함된 노드의 수
	const int N = preorder.size();

	//텅 빈 트리면 곧장 종료
	if (preorder.empty()) return;

	//이 트리의 루트는 전위탐색결과로부터 곧장 알 수 있다.
	const int root = preorder[0];

	//이 트리의 왼쪽 서브트리의 크기는 중위 탐색 결과에서 루트의 위치를 찾아서 알 수 있다.
	const int L = find(inorder.begin(), inorder.end(), root) - inorder.begin();

	//오른쪽 서브트리의 크기는 N에서 왼쪽 서브트리와 루트를 빼면 알 수 있다.
	const int R = N - 1 - L;

	//왼쪽과 오른쪽 서브트리의 순회 결과를 출력
	printPostOrder(slice(preorder, 1, L + 1), slice(inorder, 0, L));
	printPostOrder(slice(preorder, L + 1, N), slice(inorder, L + 1, N));

	cout << root << ' ';
}
int main(void) {
	int t;
	cin >> t;
	while (t--) {
		int n;
		cin >> n;
		vector<int> pre;
		vector<int> in;
		int k;
		for (int i = 0; i < n; ++i) {
			cin >> k;
			pre.push_back(k);
		}
		for (int i = 0; i < n; ++i) {
			cin >> k;
			in.push_back(k);
		}
		printPostOrder(pre, in);
	}
	return 0;
}