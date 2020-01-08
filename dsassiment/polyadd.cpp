#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>

using namespace std;

ifstream in("polyadd.inp");
ofstream out("polyadd.out");

vector<pair<int , int> > poly;

void process() {
	int t;
	in >> t;
	while(t--) {
		int tt;
		in >> tt;
		while(tt--) {
			int a, b;
			in >> a >> b;
			int i;
			for(i=0; i<poly.size();++i) {
				if(poly[i].first == b){
					poly[i].second += a;
					break;
				}
			}
			if(i == poly.size()) {
				poly.push_back(make_pair(b, a));
			}
		}
	}
	int find_zero = 0;
	for(int i=0;i<poly.size();++i) {
		if(poly[i].second == 0) {
			find_zero++;
		}
	}
	sort(poly.begin(), poly.end());
	reverse(poly.begin(), poly.end());
	out << poly.size() - find_zero << '\n';
	if(poly.size() - find_zero == 0){
		out << 0 << ' ' << 0;
		return;
	}
	for(int i=0;i<poly.size();++i) {
		if(poly[i].second != 0){
			out << poly[i].second << ' ' << poly[i].first << '\n';
		}
	}
}

int main(void) {
	process();
	return 0;
}