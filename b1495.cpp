/*
	중요했던 점. 
	경우의 수는 4가지가 있다.
	1. 더하고 빼고 둘다 s,m 범위 에 들어가는 것
	2,3 더하기만 들어가는 경우, 빼기만 들어가는 경우
	4. 둘다 안들어 가는 경우 => 불가능한 경우

	알게 모르게 4번 경우를 따로 return 값을 지정해 주지 않아 
	-1이란 값을 방문하지 않았다는 의미로 사용하려고 초기화 했는데 불가능한 의미와 중복으로 사용되어 버렸다.
	따라서 4번 경우가 있었을 때 무한루프에 빠질 수 있다. 혹은 제대로 된 메모리제이션이 불가능하다. 
	4번 경우를 따로 값을 지정해 주어 의미를 다르게 하니 정상적으로 돌아갔다. 

	참고한 답변
	Hibbah   2년 전    1 좋아요
	저도 방금 시간초과를 받았는데 같은 실수를 하셨네요.

	메모이제이션 테이블인 DP[][]에서 '아직 계산한 적이 없다.'라는 의미의 초기값을 -1로 해두셨는데,

	작성하신 코드를 보시면 반환 값 -1이 '마지막 곡을 부를 때 가능한 볼륨 값이 0~M사이에 존재하지 않는다.'라는 의미와 중복됨을 알 수 있습니다.

	예를 들어, N=100인 상황에서 현재 재귀함수의 매개변수가 X=20, Y=30이라 하고,

	현재상태에서 끝까지 볼륨조절을 어떻게 하더라도 마지막 곡을 부를때 가능한 볼륨 값이 허용 범위를 벗어난다고 가정하겠습니다.

	그러면 X=20에서 N=100까지의 무수히 많은 경우의 수에 대해 제법 깊은 재귀함수의 탐색 과정을 통해 -1을 반환하여

	DP[20][30]에는 '현재 볼륨이 30이고, 20번째 곡의 볼륨을 조절하여 마지막 곡 까지 불렀을 때' 가능한 볼륨 값이 없다는 의미로 -1이 할당되게 됩니다.

	그런데 이는 '20번째 곡을 부르기 직전에 볼륨이 30일 경우에 대해서는 계산을 해본 적이 한 번도 없다'라는 의미와 중복되므로,

	X=0 ~ 20까지의 볼륨 조절 조합으로 Y=30이 되는 모든 경우에 대해 X = 20 ~ 100까지의 굉장히 많은 탐색 공간을 매번 중복해서 계산하게 됩니다.

	.......

	간략하게 적어도 이해하실 내용을 적다보니 너무 장황하게 적은것 같네요

	결론은 '계산한 적 없다'와 '불가능하다'의 의미를 구분하도록 다른 값을 할당하시면 될 것 같습니다.

	좋은하루되십셔 ㅎ, ㅎ
*/


#include <iostream>
#include <cstring>
#include <algorithm>
#include <vector>

using namespace std;

int tb1[1001];
int cache[2001][2001];
int n, s, m;
bool finish = false;
int maxv = 0;
int go(int cnt, int cur_val) {
	if (cnt == n) {
		finish = true;
		maxv = max(cur_val, maxv);
		return cur_val;
	}

	int& ret = cache[cnt][cur_val];
	if (ret == -9999) {
		return 0;
	}
	if (ret != -1) {
		return ret;
	}
	bool nofirst = false;
	int longhate = cur_val + tb1[cnt];
	if (longhate >= 0 && longhate <= m) {
		ret = go(cnt + 1, cur_val + tb1[cnt]);
	} 
	else {
		nofirst = true;
	}
	longhate = cur_val - tb1[cnt];
	if (longhate >= 0 && longhate <= m){
		ret = go(cnt + 1, cur_val - tb1[cnt]);
	}
	else {
		if (nofirst == true) {
			ret = -9999; // 불가능
		}
	}

	return ret;

}

int main(void) {
	memset(cache, -1, sizeof(cache));
	cin >> n >> s >> m; // m은 최대 볼륨
	for (int i = 0; i < n; ++i) {
		cin >> tb1[i];
	}
	int ans = go(0,s);
	if (finish) {
		cout << maxv << '\n';
	}
	else {
		cout << -1 << endl;
	}
	return 0;
	
}