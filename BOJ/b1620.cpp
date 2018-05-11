#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <cstring>
#include <stack>
#include <queue>
#include <limits.h>
#include <map>
#include <stdlib.h>

using namespace std;

typedef unsigned long long ull;
typedef long long ll;

int n,m;
int tb1[100001];
int tb2[1001][1001];
int che2[1001][1001];
ull che1[100001];
string s[100001];

ull go(int idx, int sum){
	
}

int main(void){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cin >> n >> m;
	map<string, int> mm;
 	for(int i=1;i<=n;++i){
 		string temp;
 		cin >> temp;
 		mm.insert(pair<string,int>(temp,i));
 		s[i] = temp;
 	}
 	while(m--){
 		string input;
 		cin >> input;
 		int ifint;
 		if(input[0]<='9' && input[0]>='0'){
 			ifint = stoi(input);
 			cout << s[ifint] << '\n';
 		}
 		else{
 			cout << mm[input] << '\n';
 		}
 	}

	return 0;
}
