#include <iostream>
#include <vector>

using namespace std;

bool visited[11];
int n;

vector<int> v;
int max_sum = 0;
void print_visited() {
	//cout << "print_visited " << endl;
	for(int i=0;i<n;++i) {
		cout << visited[i] << ' ';
	}
	cout << endl;
}

void eg(int cnt, int sum) {
	//print_visited();
	if(cnt == 2) {
		if(sum > max_sum) {
			max_sum = sum;
		}
		return;
	}

	for(int i=1;i<n-1;++i) {
		if(visited[i] == true) {
			continue;
		}
		visited[i] = true;
		int left_side;
		int right_side;	
		for(int j=i-1;j>=0;--j) {
			if(visited[j] == false) {
				left_side = j;
				break;
			}
		}
		for(int j=i+1;j<n;++j) {
			if(visited[j] == false) {
				right_side = j;
				break;
			}
		}
		eg(cnt - 1, sum + v[left_side] * v[right_side]);
		visited[i] = false;
	}
}

int main(void) {
	cin >> n;
	int a;
	for(int i=0;i<n;++i) {
		cin >> a;
		v.push_back(a);
	}
	eg(n,0);
	cout << max_sum << endl;

}