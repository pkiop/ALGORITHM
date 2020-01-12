include <iostream>

using namespace std;

bool cal(int n){
    while(n != 0) {
        if(n%10 != 4 && n%10 != 7){
            return false;
        }
        n = n/10;
    }
    return true;
}
int main(void) {
  
    int n;
    cin >> n;
    while(1) {
        if( cal(n)){
            cout << n;
            return 0;
        }
        n--;
    }
}
