#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

unsigned long long afirst(unsigned long long a,unsigned long long b,unsigned long long x,unsigned long long y,unsigned long long n) {
  if(a - x < n) {
    n -= a - x;
    a = x;
    if(n > b - y) {
      b = y;
    } else {
      b -= n;
    }
  } else {
    a = a - n; 
  }
  return a * b;
}

unsigned long long bfirst(unsigned long long a,unsigned long long b,unsigned long long x,unsigned long long y,unsigned long long n) {
  if(b - y < n) {
    n -= b - y;
    b = y;
    if(n > a - x) {
      a = x;
    } else {
      a -= n;
    }
  } else {
    b = b - n; 
  }
  return a * b;
}

int main(void) {
  // freopen("input.txt", "r", stdin);
  unsigned long long t;
  cin >> t;
  while(t--) {
    unsigned long long a,b,x,y,n;
    cin >> a >> b >> x >> y >> n;
    cout << min(afirst(a,b,x,y,n), bfirst(a,b,x,y,n)) << '\n';
  }  
}