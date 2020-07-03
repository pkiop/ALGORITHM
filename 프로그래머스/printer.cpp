#include <string>
#include <vector>
#include <queue>
using namespace std;

queue<pair<int, int> > q;
int solution(vector<int> priorities, int location) {
    for(int i=0;i<priorities.size();++i) {
        q.push({priorities[i], i});
    }
    int qsize = q.size();
    while(!q.empty()) {
        int now = q.front().first;
        int nidx = q.front().second;
        q.pop();
        bool poptrue = true;
        int rep = q.size();
        for(int i=0;i<priorities.size(); ++i) {
            if(priorities[i] > now) {
                q.push({now, nidx});
                poptrue = false;
                break;
            }
        }
        if(poptrue) {
            if(nidx == location) {
                return qsize - q.size();
            }
            priorities[nidx] = -1;
        }
    }
    int answer = 0;
    return answer;
}