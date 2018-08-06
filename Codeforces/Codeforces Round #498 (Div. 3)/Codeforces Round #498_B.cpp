#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
using namespace std;

bool ch[2001]; // tk 3번에서 2000 2000 중복나오면 인덱스 구분이 안되서 추가 
// sorting 후 끝숫자로 first ans
// 그 숫자들의 원래 인덱스 찾아서 
// 첫번째 숫자가 포함된 영역은 두번째 숫자 한칸 앞까지
// 마지막 숫자 영역은 마지막 -1번째 숫자 인덱스 +1부터 n까지 
// m == 1 이면 n 이 second ans 예외처리 
int main(void) {
	int n, m;
	cin >> n >> m;
	vector<int> arr(n);
	vector<int> arr2(n);
	for (int i = 0; i < n; ++i) {
		cin >> arr[i];
		arr2[i] = arr[i];
	}
	sort(arr.begin(), arr.end());

	int firstans = 0;
	for (int j = 0; j < m; ++j) {
		firstans += arr[n - j - 1];
	}
	vector<int> index;
	for (int j = 0; j < m; ++j) {
		for (int i = 0; i < n; ++i) {
			if (arr[n - j - 1] == arr2[i] && ch[i] == false) {
				index.push_back(i);
				ch[i] = true;
				break;
			}
		}
	}
	sort(index.begin(), index.end());

	vector<int> secondans;
	int temp = 0;
	for (int i = 1; i < index.size(); ++i) {
		secondans.push_back(index[i]- temp);
		temp = index[i];
	}
	secondans.push_back(n - index[index.size() - 1]);
	cout << firstans << endl;
	if (m == 1) {
		cout << n;
		return 0;
	}
	for (int i = 0; i < secondans.size(); ++i) {
		cout << secondans[i] << ' ';
	}
	return 0;
}