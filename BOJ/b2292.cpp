#include <iostream>

using namespace std;

int main(void)
{
	int n;
	cin >> n;
	int cnt = 1;
	int cal = 1;
	int mul = 1;
	while(n>cal){
		cal += 6*mul;
		cnt++;
		mul++;
	}
	cout << cnt << endl;
	return 0;

}