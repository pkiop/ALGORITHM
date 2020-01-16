#include <iostream>
#include <vector>
#include <string>

using namespace std;

int r1,c1,r2,c2;
int table[51][51];

void insert_table(int nx, int ny, int value) {
	if(r1 <= ny && ny <= r2 && c1 <= nx && nx <= c2) {
		table[nx-5000 + -(c1-5000)][ny-5000 + -(r1-5000)] = value;
	}
	else {
		return;
	}
}

void print_table() {
	for(int i=0;i<50;++i){
		for(int x=0;x<50;++x){
			cout << table[x][i] << ' ';
		}
		cout << endl;
	}
}

int main(void) {
	cin >> r1 >> c1 >> r2 >> c2;
	r1+=5000;
	c1+=5000;
	r2+=5000;
	c2+=5000;

	int nx = 5000;
	int ny = 5000;
	int nnum = 1;
	int up_scale = 1;
	int left_scale = 2;
	int down_scale = 2;
	int right_scale = 2;
	bool first_time = true;
	int alpha = 0;
	while(1) {
		if(nx > 9999) {
			break;
		}
		if(first_time) {
			insert_table(nx, ny, nnum++);
			first_time = false;
		}
		insert_table(nx + 1, ny, nnum++);

		
		for(int i=1;i<=up_scale;++i) {
			insert_table(nx + 1, ny - i, nnum++);
		}
		for(int i = 1; i <= left_scale;++i){
			insert_table(nx + 1 - i, ny - up_scale, nnum++);
		}
		for(int i=1;i<=down_scale;++i){
			insert_table(nx - left_scale + 1, ny - up_scale + i, nnum++);
		}
		
		if(nnum>20){
				alpha--;
		}
		for(int i=1;i<=right_scale;++i){
			insert_table(nx - left_scale + 1 + i, ny + down_scale / 2 + alpha, nnum++);
		}
		nx = nx + 1;
		ny = ny + 1;
		up_scale += 2;
		left_scale += 2;
		right_scale += 2;
		down_scale += 2;
	}
	vector< string > ans;
	int max_length = 0;
	string temp;
	//cout << "do" << endl;
	for(int y = 0; y <= r2 - r1;++y){
		for(int x= 0 ; x <= c2 - c1;++x) {
			temp = to_string(table[x][y]);
			ans.push_back(temp);
			max_length = ((max_length < temp.size()) ? temp.size() : max_length );
		}
	}
	//cout << "do2" << endl;
	int cnt = 1;
	for(int i=0;i<ans.size();++i) {
		for(int j=0;j<max_length - ans[i].size();++j){
			cout << ' ';
		}
		cout << ans[i] << ' ';
		if(cnt == (c2 - c1 + 1)) {
			cout << endl;
			cnt = 0;
		}
		cnt++;
	}
	//cout << endl;
	//print_table();
}	
