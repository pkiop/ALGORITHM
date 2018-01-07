#include <iostream>

using namespace std;

int main() {
	int n, cnt_two = 0, cnt_five = 0;
	cin >> n;
	for (int i = 2; i <= n; ++i)
	{
		int tempi = i;
		while (tempi % 5 == 0) {
			cnt_five++;
			tempi /= 5;
		}
	}

	cout << cnt_five << '\n';


	return 0;
}