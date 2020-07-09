#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(vector<int> weight) {
    sort(weight.begin(), weight.end());
    int nowsum = 0;
    for(auto x : weight) {
        if(nowsum + 1 < x) {
            return nowsum + 1;
        }
        else {
            nowsum += x;
        }
    }
    return nowsum + 1;
}