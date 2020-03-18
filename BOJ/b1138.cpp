#include <iostream>
#include <vector>

using namespace std;


vector<int> arr;

bool visited[1001];
vector<int> ans;
bool flag = false;
int n;
void dfs(int depth) {
	if(ans.size() == n) {
		for(int i=0;i<ans.size();++i) {
			cout << ans[i]+1 << ' ';	

		}
		flag = true;
		return ;
	}
	for(int i=0;i<n;++i) { 
		if(visited[i] == false) {
			int big_cnt = 0;
			for(int j=0;j<depth;++j) {
				if(ans[j] > i) {
					big_cnt++;
				}
			}
			if(big_cnt == arr[i]) {
				ans.push_back(i);
				visited[i] = true;
				dfs(depth+1);
				if(flag) {
					return;
				}
				visited[i] = false;
				ans.pop_back();
			}
		}
	}
}

int main(void) {
	cin >> n;
	int temp;
	for(int i=0;i<n;++i) {
		cin >> temp;
		arr.push_back(temp);
	}

	dfs(0);
	return 0;

}
