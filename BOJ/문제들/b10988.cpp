#include <iostream>
#include <string>
using namespace std;
int main(void)
{
        string s;
        cin >> s;
        int len = s.size();
        int len2 = len / 2;
        for (int i = 0; i < len2; ++i) {
               if (s[i] != s[len - i-1]) {
                       cout << "0";
                       return 0;
               }
        }
        cout << "1" << endl;
        return 0;
}