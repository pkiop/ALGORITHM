#include <iostream>
#include <set>
#include <vector>

using namespace std;

int n, k;
vector<int> angle;
vector<int> output;
void input() {
  cin >> n >> k;
  int temp;
  for(int i=0;i<n;++i) {
    cin >> temp;
    angle.push_back(temp);
  }
  for(int i=0;i<k;++i) {
    cin >> temp;
    output.push_back(temp);
  }
}

int convert(int num) {
  if(num >= 360) {
    return num - 360;
  }
  if(num < 0) {
    return num + 360;
  }
  return num;
}

set<int> ans;
void process() {
  int nowAnsLength = 0; 
  for(int i=0;i<angle.size(); ++i) {
    ans.insert(convert(angle[i]));
  }
  for(int i=0;i<angle.size(); ++i) {
    for(int j=0;j<angle.size(); ++j) {
      ans.insert(convert(angle[i] + angle[j]));
      ans.insert(convert(angle[i] - angle[j]));
    }
  }
  while(nowAnsLength != ans.size()) {
    nowAnsLength = ans.size();
    vector<int> temp_vec;
    for(auto x : ans) {
      temp_vec.push_back(x);
    }
    for(int i=0;i<temp_vec.size(); ++i) {
      for(int j=0;j<temp_vec.size(); ++j) {
        ans.insert(convert(temp_vec[i] + temp_vec[j]));
        ans.insert(convert(temp_vec[i] - temp_vec[j]));
      }
    }
  }
  for(int i=0;i<output.size();++i) {
    if(ans.count(output[i]) == 0) {
      cout << "NO" << endl;
    } else {
      cout << "YES" << endl;
    }
  }
  return;
}

int main(void) {
  input();
  process();
}