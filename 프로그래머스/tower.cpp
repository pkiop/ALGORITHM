#include <string>
#include <vector>
#include <stack>

using namespace std;

stack<pair<int, int> > st;
int ans[101];
vector<int> solution(vector<int> heights) {
    
    vector<int> answer;
    for(int i=heights.size()-1;i >= 0; --i) {
        if(st.empty() || st.top().first >= heights[i]) {
            st.push({heights[i], i});
            continue;
        } 
        while(st.top().first < heights[i]) {
            int stidx = st.top().second;
            ans[stidx] = i+1;
            st.pop();
            if(st.empty()) {
                break;
            }
        }
        st.push({heights[i], i});
    }
    for(int i=0;i<heights.size();++i) {
        answer.push_back(ans[i]);
    }
    return answer;
}