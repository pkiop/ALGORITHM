#include <string>
#include <vector>
#include <iostream>
#include <set>
using namespace std;

int rowsize;
int colsize;
vector<string> arr[201];
bool visited[201];

void makearr(vector<vector<string> >& relation) {
    for(int j=0;j<relation.size();++j) {
        for(int i=0;i<relation[0].size();++i) {
            arr[i].push_back(relation[j][i]);
        }
    }
}

vector<pair<string, vector<int> > > temp;
vector<int> whoareyou;
void makeKey(int depth, int maxDepth, int nowidx, int loca, string nowstring) {
    if(depth == maxDepth){
        temp.push_back({nowstring, whoareyou});
        return;
    }
    for(int i=nowidx;i<colsize;++i) {
        if(visited[i] == true) continue;
        string newstring = nowstring + arr[i][loca];
        visited[i] = true;
        whoareyou.push_back(i);
        makeKey(depth+1, maxDepth,i, loca, newstring);
        whoareyou.pop_back();
        visited[i] = false;
    }
}

vector<vector<int> > isOK;
bool iscontain(vector<int> suchubo) {
    for(auto x : isOK) {
        int matchcnt = 0;
        for(auto y : x) {
            for(auto z : suchubo) {
                if(y == z) {
                    matchcnt++;
                    break;
                }
            }
        }
        if(matchcnt == x.size()) return true;
    }
    isOK.push_back(suchubo);
    return false;
}

vector<vector<pair<string, vector<int> > > > hubo[90];
int solution(vector<vector<string>> relation) {
    int answer = 0;
    rowsize = relation.size();
    colsize = relation[0].size();
    makearr(relation);
    for(int depth = 1; depth <= colsize; ++depth) {
        for(int loca = 0; loca<rowsize;++loca) {
            makeKey(0, depth,0, loca, "");
            hubo[depth].push_back(temp);
            temp.clear();
        }
    }
    for(int depth=1;depth<=colsize;++depth) {
        cout << "****depth " << depth << "*****" << endl;
        for(auto x : hubo[depth]) {
            for(auto y : x) {
                cout << y.first << ' ';
                cout << " contain : ";
                for(auto z : y.second) {
                    cout << z << ' ';
                }
                cout << endl;
            }
            cout << endl;
        }
        cout << endl;
    }

    for(int depth=1;depth<=colsize;++depth) {
        set<string> us[400]; 
        int middlesize = hubo[1][0].size();

        for(int big=0;big<rowsize; ++big) {
            cout << "hubo :: ";
            cout << hubo[depth][big].size() << endl;
            for(int middle = 0; middle<hubo[depth][big].size(); ++middle) {
                us[middle].insert(hubo[depth][big][middle].first);
            }
        }
        for(int i=0;i< middlesize ;++i) {
            if(us[i].size() == rowsize) { // 유효성 만족
                if(iscontain(hubo[depth][0][i].second)) continue; // 최소성 만족
                answer++;
            }
        }
    }
    int tidx = 0;
    cout << "answers" << endl;
    for(auto x : isOK) {
        cout << "idx : " << ++tidx << " : ";
        for(auto y : x) {
            cout << y << ' ';
        }
        cout << endl;
    }
    return answer;
}#include <string>
#include <vector>
#include <iostream>
#include <set>
using namespace std;

int rowsize;
int colsize;
vector<string> arr[201];
bool visited[201];

void makearr(vector<vector<string> >& relation) {
    for(int j=0;j<relation.size();++j) {
        for(int i=0;i<relation[0].size();++i) {
            arr[i].push_back(relation[j][i]);
        }
    }
}

vector<pair<string, vector<int> > > temp;
vector<int> whoareyou;
void makeKey(int depth, int maxDepth, int nowidx, int loca, string nowstring) {
    if(depth == maxDepth){
        temp.push_back({nowstring, whoareyou});
        return;
    }
    for(int i=nowidx;i<colsize;++i) {
        if(visited[i] == true) continue;
        string newstring = nowstring + arr[i][loca];
        visited[i] = true;
        whoareyou.push_back(i);
        makeKey(depth+1, maxDepth,i, loca, newstring);
        whoareyou.pop_back();
        visited[i] = false;
    }
}

vector<vector<int> > isOK;
bool iscontain(vector<int> suchubo) {
    for(auto x : isOK) {
        int matchcnt = 0;
        for(auto y : x) {
            for(auto z : suchubo) {
                if(y == z) {
                    matchcnt++;
                    break;
                }
            }
        }
        if(matchcnt == x.size()) return true;
    }
    isOK.push_back(suchubo);
    return false;
}

vector<vector<pair<string, vector<int> > > > hubo[90];
int solution(vector<vector<string>> relation) {
    int answer = 0;
    rowsize = relation.size();
    colsize = relation[0].size();
    makearr(relation);
    for(int depth = 1; depth <= colsize; ++depth) {
        for(int loca = 0; loca<rowsize;++loca) {
            makeKey(0, depth,0, loca, "");
            hubo[depth].push_back(temp);
            temp.clear();
        }
    }
    for(int depth=1;depth<=colsize;++depth) {
        cout << "****depth " << depth << "*****" << endl;
        for(auto x : hubo[depth]) {
            for(auto y : x) {
                cout << y.first << ' ';
                cout << " contain : ";
                for(auto z : y.second) {
                    cout << z << ' ';
                }
                cout << endl;
            }
            cout << endl;
        }
        cout << endl;
    }

    for(int depth=1;depth<=colsize;++depth) {
        set<string> us[400]; 
        int middlesize = hubo[1][0].size();

        for(int big=0;big<rowsize; ++big) {
            cout << "hubo :: ";
            cout << hubo[depth][big].size() << endl;
            for(int middle = 0; middle<hubo[depth][big].size(); ++middle) {
                us[middle].insert(hubo[depth][big][middle].first);
            }
        }
        for(int i=0;i< middlesize ;++i) {
            if(us[i].size() == rowsize) { // 유효성 만족
                if(iscontain(hubo[depth][0][i].second)) continue; // 최소성 만족
                answer++;
            }
        }
    }
    int tidx = 0;
    cout << "answers" << endl;
    for(auto x : isOK) {
        cout << "idx : " << ++tidx << " : ";
        for(auto y : x) {
            cout << y << ' ';
        }
        cout << endl;
    }
    return answer;
}
