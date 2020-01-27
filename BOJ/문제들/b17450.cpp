#include <iostream>

using namespace std;

int main(void) {
	int price[3];
	int weight[3];
	double value[3] = { 0, };
	for (int i = 0; i < 3; ++i) {
		cin >> price[i] >> weight[i];
		price[i] *= 10;
		weight[i] *= 10;
	}

	for (int i = 0; i < 3; ++i) {
		if (price[i] >= 5000) {
			price[i] -= 500;
		}
		value[i] = double(weight[i]) / double(price[i]);
	}
	double ans = 0.0;
	int ansi;
	for (int i = 0; i < 3; ++i) {
		//cout << value[i] << endl;
		if (value[i] > ans) {
			ans = value[i];
			ansi = i;
		}
	}

	switch (ansi) {
	case 0:
		cout << 'S' << endl;
		break;
	case 1:
		cout << 'N' << endl;
		break;
	case 2:
		cout << 'U' << endl;
		break;
	};

	return 0;

}
