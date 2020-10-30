#include <iostream>
#include <sstream>
#include <vector>

using namespace std;

int badmanLocation = 0; // 술래<
char badman = 'A';
int players;
char playerArray[26];
int qpNum;
char* quickPlayer;

int ans[26];
bool isQp(int lo) {
  for(int i=0;i<qpNum;++i) {
    if(playerArray[lo] == qpNum[i]) {
      return true;
    }
  }
  return false;
}
void run (int move) {
  badmanLocation = (badmanLocation + move) % players;
  if(isQp(badmanLocation))  {
    ans[badman - 'A']++;
  } else {
    char temp = badman;
    badman = playerArray[badmanLocation];
    playerArray[badmanLocation] = temp;
    ans[badman - 'A']++;
  }
}

void solution(int numOfAllPlayers, int numOfQuickPlayers, char *namesOfQuickPlayers, int numOfGames, int *numOfMovesPerGame) {
  players = numOfAllPlayers;
  qpNum = numOfQuickPlayers;
  quickPlayer = namesOfQuickPlayers;

  for(int i=0;i<players;++i) {
    playerArray[i] = 'A' + i;
  }
  // TODO: 이곳에 코드를 작성하세요. 추가로 필요한 함수와 전역변수를 선언해서 사용하셔도 됩니다.

	for(int i=0;i<numOfGames;++i) {
		run(numOfMovesPerGame[i]);
	}
