#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <cstring>

using namespace std;

typedef long long ll;

const int M = 1000000000 + 100;
int bino[201][201];
int skip;

void calcBino() {
	memset(bino, 0, sizeof(bino));
	for (int i = 0; i <= 200; ++i) {
		bino[i][0] = bino[i][i] = 1;
		for (int j = 1; j < i; ++j)
			bino[i][j] = min(M, bino[i - 1][j - 1] + bino[i - 1][j]);
	}
}

void generate3(int n, int m, string s) {
	if (skip < 0) return;
	if (n == 0 && m == 0) {
		if (skip == 0) cout << s << endl;
		--skip;
		return;
	}
	if (bino[n + m][n] <= skip) {
		skip -= bino[n + m][n];
		return;
	}
	if (n > 0) generate3(n - 1, m, s + "-");
	if (m > 0) generate3(n, m - 1, s + "o");
}

void generate(int n, int m, string s) {
	// 기저 사례 n == m == 0
	if (n == 0 && m == 0) {
		cout << s << endl;
		return;
	}
	if (n > 0) generate(n - 1, m, s + "-");
	if (m > 0) generate(n, m - 1, s + "o");
}
void generate2(int n, int m, string s) {
	//기저 사례: skip < 0
	if (skip < 0) return;
	if (n == 0 && m == 0) {
		if (skip == 0) cout << s << endl;
		--skip;
		return;
	}
	if (n > 0) generate2(n - 1, m, s + "-");
	if (m > 0) generate2(n, m - 1, s + "o");
}

int main(void) {
	int t;
	cin >> t;
	calcBino();
	while (t--) {
		int n, m;
		cin >> n >> m >> skip;
		skip--;
		string temp = "";
		generate3(n, m, temp);
	}
	return 0;
}