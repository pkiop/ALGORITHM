#include <iostream>
#include <set>
#include <cmath>

using namespace std;

int main(void) {
	int a, b;
	cin >> a >> b;
	set<int> se;
	int temp;
	for (int i = 0; i < a; ++i) {
		
		cin >> temp;
		se.insert(temp);
	}
	for (int i = 0; i < b; ++i) {
		cin >> temp;
		se.insert(temp);
	}
	cout <<(a+b) - 2*(a+b - se.size()) << endl;
	return 0;
}