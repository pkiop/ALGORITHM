#include <string>
#include <vector>
#include <algorithm>
using namespace std;

int arr[31];
int solution(int n, vector<int> lost, vector<int> reserve) {
    sort(reserve.begin(), reserve.end());
    int answer = 0;
    for(int i=0;i<31;++i) {
        arr[i] = 1;
    }
    for(auto x : lost) {
        arr[x] = 0;
    }
    for(auto x : reserve) {
        if(arr[x] == 0) {
            arr[x] = 1;
            continue;
        }
        
        if(x == 1) {
            arr[x+1]++;
        }
        else if(x == n) {
            arr[x-1]++;
        }
        else {
            if(arr[x-1] == 0) {
                arr[x-1]++;
            }
            else {
                arr[x+1]++;
            }
        }
    }
    for(int i=1;i<=n;++i)
        if(arr[i] > 0) 
            answer++;
    
    
    return answer;
}