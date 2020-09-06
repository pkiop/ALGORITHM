#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <cstring>

using namespace std;

vector<int> origin;
vector<int> arr;
vector<int> ans;
int n;
bool finish = false;
int visited[10001];
bool visitedonenum[101];
bool chk() {
  for(int i=0;i<n;++i) {
    if(origin[i] != ans[i]) {
      return true;
    }
  }
  return false;
}

int idx = 0;
void dfs(int firstnum) {
  // cout << "temp :: " << idx << endl;
  // for(int i=0;i<ans.size();++i) {
  //   cout << ans[i] << ' ';
  // }
  // cout << endl;
  if(n == idx) {
    if(chk() == false) {
      return;
    }
    for(int i=0;i<ans.size();++i) {
      cout << ans[i] << ' ';
    }
    cout << endl;
    finish = true;
    return;
  }
  
  if(finish) {
    return;
  }

  for(int i=1;i<=n;++i) {
    if(visitedonenum[i] == false && visited[i + firstnum] > 0) {
      visitedonenum[i] = true; 
      visited[i + firstnum]--;
      ans.push_back(i);
      idx++;
      dfs(i);
      visitedonenum[i] = false; 
      idx--;
      ans.pop_back();
      visited[i + firstnum]++;
    }
  }
}

int main(void) {
  // freopen("input.txt", "r", stdin);
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int t;
  cin >> t;
  while(t--) {
    cin >> n;
    origin.clear();
    int temp;
    for(int i=0;i<n;++i) {
      cin >> temp;
      origin.push_back(temp);
    }
    for(int i=origin.size() - 1; i>=0;--i) {
      cout << origin[i] << ' '; 
    }
    cout << endl;
  }
  return 0;
}