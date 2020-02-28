
#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

vector<vector<int> > combi;
bool visited[4];
vector<int> input;
vector<int> arr;
void find(int cnt) {
	if(cnt == 4) {
		combi.push_back(input);
		return;
	}

	for(int i=0;i<4;++i) {
		if(visited[i] == false) {
			visited[i] = true;
			input.push_back(i);
			find(cnt+1);
			input.pop_back();
			visited[i] = false;
		}
	}
}
int main(void) {

	sort(arr.begin(), arr.end());
	int n;

	for(int i=0;i<4;++i) {	
		cin >> n;
		arr.push_back(n);
	}
	find(0);

	int ans = 0;
	for(int i=0;i<combi.size();++i) {

		if(arr[combi[i][0]] <= arr[combi[i][2]] && arr[combi[i][1]] <= arr[combi[i][3]]) {
			ans = max(ans, min(arr[combi[i][0]],arr[combi[i][2]]) * min(arr[combi[i][1]],arr[combi[i][3]]));
		}
	}
	cout << ans << endl;

}
