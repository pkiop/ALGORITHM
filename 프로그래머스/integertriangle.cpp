#include <string>
#include <vector>

using namespace std;

int dp[510][510];
vector<vector<int> > *arr;

void init() {
    for(int i=0;i<510;++i) {
        for(int j=0;j<510;++j) {
            dp[i][j] = 0;
        }
    }
}

int dfs(int depth, int idx) {
    if(depth == arr->size()) {
        return 0;
    }    
    if(dp[depth][idx] != 0) {
        return dp[depth][idx];
    }
    
    dp[depth][idx] = max((*arr)[depth][idx] + dfs(depth + 1, idx), (*arr)[depth][idx] + dfs(depth + 1, idx + 1));    
 
   
    return max(dp[depth][idx], dp[depth][idx+1]);
}

int solution(vector<vector<int>> triangle) {
    arr = &triangle;
    init();
    int answer = 0;
    answer = dfs(0,0);
    return answer;
}