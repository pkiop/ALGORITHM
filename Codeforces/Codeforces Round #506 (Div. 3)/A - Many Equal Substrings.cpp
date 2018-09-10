#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main(void) {
	int n, k;
	string s;

	cin >> n >> k;
	cin >> s;

	//겹치는 부분 찾기
	int f_idx = 0;
	 
	//두번째 글자 == 첫번째 글자 ... 이렇게 최대로 겹칠 수 있는 경우 찾는다.
	for (int i = 1; i < n; ++i) {
		for (int j = 0; j < n - i; ++j) {
			if (s[j+i] != s[j])
				break;
			if (j == n - i - 1) {
				f_idx = i;
			}
		}
		if (f_idx != 0)
			break;
	}
	//겹칠수 있는 경우가 없으면 그냥 두번 출력하고 종료
	if (f_idx == 0) {
		for (int i = 0; i < k; ++i) {
			cout << s;
		}
		return 0;
	}
	f_idx = n - f_idx;
	//찾아서 출력
	cout << s;
	for (int i = 0; i < k - 1; ++i) {
		for (int j = f_idx; j < n; ++j) {
			cout << s[j];
		}
	}
	return 0;
}