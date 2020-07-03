#include <string>
#include <vector>
#include <map>
#include <algorithm>
#include <iostream>

using namespace std;

vector<pair<int, int> > genresSum(101);
vector<int> solution(vector<string> genres, vector<int> plays) {
    map<string, int> m;
    vector<pair<int, int> > arr[101];
    vector<int> ret;

    int idx = 1;
    for(int i=0;i<genres.size();++i) {
        int nowGidx = m[genres[i]];
        if(nowGidx == 0) {
            nowGidx = m[genres[i]] = idx++;
        }
        arr[nowGidx].push_back({plays[i], -1*i});
        genresSum[nowGidx].first += plays[i];
        
    }
    for(int i=0;i<genresSum.size();++i) {
        genresSum[i].second = -i;
    }
    sort(genresSum.begin(), genresSum.end());

    for(int i=genresSum.size()-1;i>=0;--i) {
        if(genresSum[i].first == 0) {
            break;
        }
        int nowGidx = -1*genresSum[i].second;
        sort(arr[nowGidx].begin(), arr[nowGidx].end());
        int cnt = 0;
        for(int i=arr[nowGidx].size()-1; i >= 0; --i) {
            ret.push_back(-1*arr[nowGidx][i].second);
            cnt++;
            if(cnt == 2) break;
        }
    }
    


    
    return ret;
}