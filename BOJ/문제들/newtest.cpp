#include <iostream>

using namespace std;

int main()
{
  cout << "abc address : " << &"abc" << endl;
  cout << "abcd address : " << &("abc" + "d") << endl;

  string str = "abc";
  cout << "str address : " << &str << endl;
}
