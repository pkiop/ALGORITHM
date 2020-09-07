#include <iostream>

using namespace std;

class numberstore {
public:
  char arr[24][13];
  int rowSize;
  int colSize;
  int size;
  numberstore() {}
  void setnumberstore(int sz, char num) {
    for(int i=0;i<24;++i) {
      for(int j=0;j<13;++j) {
        arr[i][j] = ' ';
      }
    }
    size = sz;
    rowSize = sz * 2 + 3;
    colSize = sz + 2;
    draw(num);
  }

  void draw(char num) {
    if(num == '0') {
      for(int i=1;i<colSize-1;++i) {
        arr[0][i] = arr[rowSize-1][i] = '-';
      }
      for(int i=1;i<rowSize-1;++i) {
        if(i == rowSize / 2) continue;
        arr[i][0] = arr[i][colSize-1] = '|';
      }
    }

    if(num == '1') {
      for(int i=1;i<rowSize-1;++i) {
        if(i == rowSize / 2) continue;
        arr[i][colSize-1] = '|';
      }
    }

    if(num == '2' || num == '3') {
      for(int i=1;i<colSize-1;++i) {
        arr[0][i] = arr[rowSize / 2][i] = arr[rowSize-1][i] = '-';
      }

      for(int i=1;i<rowSize-1;++i) {
        if(i == rowSize / 2) continue;
        if(i < rowSize / 2) {
          arr[i][colSize-1] = '|';
        } else {
          if(num == '2') {
            arr[i][0] = '|';
          } else if(num == '3') {
            arr[i][colSize-1] = '|';
          }
        }
      }
    }

    if(num == '4') {
      for(int i=1;i<colSize-1;++i) {
        arr[rowSize / 2][i] = '-';
      }

      for(int i=1;i<rowSize-1;++i) {
        if(i == rowSize / 2) continue;
        if(i < rowSize / 2) {
          arr[i][0] = arr[i][colSize-1] = '|';
        } else {
          arr[i][colSize-1] = '|';
        }
      }
    }

    if(num == '5' || num == '6' || num == '8' || num == '9') {
      for(int i=1;i<colSize-1;++i) {
        arr[0][i] = arr[rowSize / 2][i] = arr[rowSize-1][i] = '-';
      }

      for(int i=1;i<rowSize-1;++i) {
        if(i == rowSize / 2) continue;
        if(i < rowSize / 2) {
          if(num == '8' || num == '9') {
            arr[i][colSize-1] = '|';
          }
          arr[i][0] = '|';
        } else {
          if(num == '5') {
            arr[i][colSize-1] = '|';
          } else if(num == '6' || num == '8') {
            arr[i][0] = arr[i][colSize-1] = '|';
          } else if(num == '9') {
            arr[i][colSize-1] = '|';
          }
        }
      }
    }

    if(num == '7') {
      for(int i=1;i<colSize-1;++i) {
        arr[0][i]= '-';
      }

      for(int i=1;i<rowSize-1;++i) {
        if(i == rowSize / 2) continue;
        arr[i][colSize - 1] = '|';
      }
    }
  }

  void printRow(int row) {
    for(int i=0;i<colSize;++i) {
      cout << arr[row][i]; 
    }
  }
  

  void oneprint() {
    for(int i=0;i<rowSize;++i) {
      for(int j=0;j<colSize;++j) {
        cout << arr[i][j];
      }
      cout << endl;
    }
  }

};

int main(void) {
  int s; 
  string n;
  cin >> s >> n;
  numberstore ns[100];
  for(int i=0;i<n.size();++i) {
    ns[i].setnumberstore(s, n[i]);
  }

  for(int i=0;i<2 * s + 3;++i) {
    for(int j=0;j<n.size();++j) {
      ns[j].printRow(i);
      cout << ' ';
    }
    cout << endl;
  }
  return 0; 
}

/*
9999999999
*/