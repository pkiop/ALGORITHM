#include <iostream>
#include <math.h>
#include <algorithm>

using namespace std;

int main(void)
{
	double h1,h2,d,h;
	double x,y,c;
	double left, right, mid;
	cout<<fixed;
	cout.precision(3);
	cout.setf(ios::showpoint);
	while(cin >> x >> y >> c){
		left = 0.0;
		right = min(x,y);
		for(int i=0;i<10000;++i){
			
			
			d = (left + right) / 2.0;

			h1 = sqrt(x*x - d*d);
			h2 = sqrt(y*y - d*d);

			h = (h1 * h2) / (h1 + h2);

			if(h > c){
				left = d;
			}
			else{
				right = d;
			}
		}
		cout << left << endl;
	}
	return 0;


}