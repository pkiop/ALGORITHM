#include <bits/stdc++.h>
using namespace std;

int main() {

    vector < tuple<int, int, int> > v;
    tuple<int, int, int>  myt ;
    myt = make_tuple( 3, 12,  7) ;

    v.push_back( make_tuple(10, 20, 30));
    v.push_back( make_tuple(15,  5, 25));
    v.push_back( make_tuple( 3,  2,  1));
    v.push_back( make_tuple( 6, 10,  4));
    v.push_back( make_tuple(15,  4,  2));
    v.push_back( myt );
    v.push_back( make_tuple( 3,  7, 11));
    v.push_back( make_tuple(16,  0, 14));
    v.push_back( make_tuple( 1, 14,  8));
    v.push_back( make_tuple( 6, -5,  5));

    sort(v.begin(), v.end());
    cout << " 정렬이후 v의 결과 \n";
    for (int i = 0; i < v.size(); i++)
        printf("\n ( %2d, %2d, %2d )", get<0>(v[i]), get<1>(v[i]), get<2>(v[i]) ) ;

    return 0;
}
