#include <iostream>
#include <cstring>
#include <list>

using namespace std;

list<pair<int,int>> snake;
bool tb2[1001][1001];
int turn = 0;//0 : 동 1 : 남 2 : 서 3 : 북 시계뱡향으로 증가 

void go(int min){
	if(turn == 0){
		for(int i=0;i<min;++i){

		}
	}
}

int main(void){
	int size;
	cin >> size;
	
	int n1,n2;
	cin >> n1;
	for(int i=0;i<n1;++i){ // apple's location
		memset(tb2,false,sizeof(tb2));
		int a,b;
		cin >> a >> b;
		tb2[a][b] = true;
	}

	cin >> n2;
	snake.push_back(0).first;
	for(int i=0;i<n2;++i){//snake's turn
		int a;
		char b;
		cin >> a >> b;
		
		go(a);

		if(b == 'D'){ //
			if(turn==3){
				turn = 0;
			}
			else{
				turn++;
			}
		}
		else{
			if(turn == 0){
				turn = 3;
			}
			else{
				turn--;
			}
		}
	}
}