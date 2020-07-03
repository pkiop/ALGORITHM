#include <string>
#include <vector>
#include <string>
#include <algorithm>
#include <iostream>

using namespace std;

vector<string> arr;

void printarr(void) {
    for(int i=0;i<arr.size();++i) {
        cout << arr[i] << ' ';
    }
    cout << endl;
}
void sort(int depth) {
    cout << "depth : " << depth << endl;
    vector<pair<char, int> > temp;
    vector<string> tt;
    for(int i=0;i<arr.size();++i) {
        tt.push_back(arr[i]);
    }

    for(int i=0;i<arr.size();++i) {
        if(arr[i].size() < depth + 1) {
            continue;
        }
        temp.push_back({arr[i][depth], i});
    }
    sort(temp.begin(), temp.end());
    reverse(temp.begin(), temp.end());
    cout << "temp size" << endl;
    for(int i=0;i<temp.size();++i) {
        cout << temp[i].first << ' ' << temp[i].second << '\n';
    }
    cout << endl;
    int didx = 0;
    for(int i=0;i<temp.size();++i) {
        int tidx = temp[i].second;
        while(arr[didx].size() < depth + 1) {
            didx++;
        }
        arr[didx++] = tt[tidx];
    }
    cout << "sorting finish " << endl;
    printarr();

}

bool cmp(string& a, string& b) {
    return a + b > b + a;
}

string solution(vector<int> numbers) {
    string answer = "";
    cout << "temp" << endl;
    for(int i=0;i<numbers.size();++i) {
        arr.push_back(to_string(numbers[i]));
    }

    sort(arr.begin(),arr.end(),cmp);

    if(arr[0][0] == '0') return "0";

    for(int i=0;i<arr.size();++i) {
        answer += arr[i];
    }
    return answer;
}