#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

int main(void) {
  // freopen("input.txt", "r", stdin);
  int t;
  cin >> t;
  while(t--) {
    int n, x, y;
    cin >> n >> x >> y;
    bool findanswer = false;
    for(int diff=1; diff<=50;++diff) {
      for(int start=1;start<=x;++start) {
        vector<int> temp;
        bool visitx = false;
        bool visity = false;
        for(int i=0;i<n;++i) {
          int nowv = start + diff*i;
          temp.push_back(nowv);
          if(nowv == x) {
            visitx = true;
          }
          if(nowv == y) {
            visity = true;
          }
        }
        if(visitx && visity) {
          for(int i=0;i<temp.size();++i) {
            cout << temp[i] << ' ';
          }
          cout << endl;
          findanswer = true;
        }
        if(findanswer) {
          break;
        }
      }
      if(findanswer) {
        break;
      }
    }
  }
}