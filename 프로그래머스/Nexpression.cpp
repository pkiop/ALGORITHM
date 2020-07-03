#include <string>
#include <vector>
#include <algorithm>
using namespace std;

int numb;
int minans = 99999;
int n;
int tenexp(int exp) {
    int ret = 1;
    for(int i=0;i<exp;++i) {
        ret *= 10;
    }
    return ret;
}

int makeManynum(int iter) {
    int ret = 0;
    for(int i=0;i<iter;++i) {
        ret += n * tenexp(i);
    }    
    return ret;
}

void dfs(int value, int depth) {
    if(depth == 9) {
        return;
    }
    if(depth >= minans) {
        return;
    }
    if(value == numb) {
        minans = min(minans, depth);
        return;
    }

    for(int i=1;i<=8-depth;++i) {
        int num = makeManynum(i);
        dfs(num + value, depth + i);
        dfs(num - value, depth + i);
        dfs(value - num, depth + i);
        dfs(value * num, depth + i);
        if(num > 0)
            dfs(value / num, depth + i);
        if(value > 0)
            dfs(num / value, depth + i);
    }
    return;
}
int solution(int N, int number) {
    numb = number;
    n = N;
    dfs(0,0);
    if(minans == 99999)
        return -1;
    return minans;
}