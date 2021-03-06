#include <string>
#include <vector>
#include <string>
#include <algorithm>
#include <iostream>

using namespace std;

vector<string> arr;

bool cmp(string& a, string& b) {
    return a + b > b + a;
}

string solution(vector<int> numbers) {
    string answer = "";
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