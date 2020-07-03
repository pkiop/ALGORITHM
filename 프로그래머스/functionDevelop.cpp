#include <string>
#include <vector>
#include <queue>

using namespace std;

queue<int> q;
vector<int> solution(vector<int> progresses, vector<int> speeds) {
    vector<int> answer;

    for(int i=0;i<progresses.size();++i) {
        int cal = (100 - progresses[i]) / speeds[i];
        int ret = (100 - progresses[i]) % speeds[i];
        if(ret != 0) {
            cal++;
        }
        q.push(cal);
    }
    int time = 0;
    
    while(!q.empty()) {
        time++;
        int ans = 0;
        while(q.front() <= time) {
            ans++;
            q.pop();
            if(q.empty()) {
                break;
            }
        }
        if(ans != 0) {
            answer.push_back(ans);
        }
        
    }
    return answer;
}